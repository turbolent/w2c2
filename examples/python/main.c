#if defined(__MWERKS__) && defined(macintosh)
#include <MacMemory.h>
#include <Files.h>
#define __bool_true_false_are_defined
typedef char bool;
#endif

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#ifdef __MSL__
#include <SIOUX.h>
#include <console.h>
#endif

#ifdef __wii__
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <fat.h>
#endif

#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "python.h"

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
#ifdef __wii__
    VIDEO_WaitVSync();
#endif
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return python_memory((pythonInstance*)instance);
}

#if defined(__MSL__) && defined(macintosh)
char** environ = {NULL};
#else
extern char** environ;
#endif

#ifdef __wii__
static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void
wiiInitVideo() {
	VIDEO_Init();
	WPAD_Init();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if (rmode->viTVMode & VI_NON_INTERLACE) {
        VIDEO_WaitVSync();
    }
}
#endif

/* Systems like OPENSTEP do not provide getcwd, but have getwd */
#if HAS_GETWD
#include <sys/param.h>
#include <errno.h>

extern char* getwd();

#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif

char* getcwd(
    char* buf,
    int len
) {
    char tmp[MAXPATHLEN];
    char* result = getwd(tmp);
    if (result) {
        if (strlen(tmp) >= len) {
            return NULL;
        }
        strcpy(buf, tmp);
    }
    return buf;
}
#endif

#define PYTHONHOME_VAR "PYTHONHOME="

bool
hasPrefix(
    const char* string,
    const char* prefix
) {
    char cs = 0;
    char cp = 0;

    while ((cp = *prefix++)) {
        cs = *string++;
        if (cp != cs) {
            return false;
        }
        if (!cs) {
            break;
        }
    }

    return true;
}

U32 exitCode = 0;

void
procExit(
    struct pythonInstance* UNUSED(instance),
    U32 code
) {
#ifdef __wii__
    VIDEO_WaitVSync();
#endif
    fprintf(stderr, "EXIT: %d\n", code);
    exitCode = code;
}

/* Main */

int main(int argc, char* argv[]) {
    char cwd[PATH_MAX];
    char** newEnviron = NULL;
    char* pythonHomeVar = NULL;

#if defined(__MWERKS__) && defined(macintosh)
    MaxApplZone();
    MoreMasters();
    MoreMasters();

    argc = ccommand(&argv);
#endif

#ifdef __wii__
    /* TODO: get interactive console working */
    argc = 3;
    argv = (char*[]){"python", "-c", "print(); print(\"Python 3.11 on the Wii!\\n\"); import sys; print(sys.version)", NULL};

    wiiInitVideo();
    fatInitDefault();
#endif

    /*
     * Ensure the PYTHONHOME environment variable is set.
     * Default to the current working directory.
     */
    {
        bool hasPythonHome = false;
        char** e = environ;
        int count = 0;
        for (; *e != NULL; e++) {
            count++;
            if (hasPrefix(*e, PYTHONHOME_VAR)) {
                hasPythonHome = true;
            }
        }

        if (!hasPythonHome) {
#ifdef __wii__
            strcpy(cwd, "/");
#else
            if (getcwd(cwd, PATH_MAX) == NULL) {
                fprintf(stderr, "failed to get current working directory: %s\n", strerror(errno));
                return 1;
            }
            wasiFromNativePath(cwd);
#endif /* __wii__ */

            fprintf(stderr, "(Automatically setting PYTHONHOME to %s)\n", cwd);

            /* 2: new entry + NULL */
            newEnviron = calloc(sizeof(char*) * (count + 2), 1);
            memcpy(newEnviron, environ, count * sizeof(char*));

            pythonHomeVar = calloc(sizeof(char) * (strlen(PYTHONHOME_VAR) + strlen(cwd) + 1), 1);
            strcat(pythonHomeVar, PYTHONHOME_VAR);
            strcat(pythonHomeVar, cwd);

            newEnviron[count] = pythonHomeVar;

            environ = newEnviron;
        }
    }

    /* Initialize WASI */
    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

#ifdef __MSL__
    SIOUXSetTitle("\pPython");
#endif

    {
        pythonInstance instance;
        pythonInstantiate(&instance, wasiResolveImport);

        instance.wasiX5FsnapshotX5Fpreview1_procX5Fexit = procExit;

        python_X5Fstart(&instance);
        pythonFreeInstance(&instance);
    }

#ifdef __wii__
	while(1) {
        u32 pressed = 0;
		VIDEO_WaitVSync();
		WPAD_ScanPads();
	    pressed = WPAD_ButtonsDown(0);
		if (pressed & WPAD_BUTTON_HOME) {
			exit(0);
		}
	}
#endif

    if (newEnviron) {
        free(newEnviron);
    }
    if (pythonHomeVar) {
        free(pythonHomeVar);
    }

    return exitCode;
}
