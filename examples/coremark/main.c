#if defined(__MWERKS__) && defined(macintosh)
#include <MacMemory.h>
#define __bool_true_false_are_defined
typedef char bool;
#endif

#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "coremark.h"
#include <unistd.h>

#ifdef __MSL__
#include <SIOUX.h>
#endif

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    void* instance
) {
    return coremark_memory((coremarkInstance*)instance);
}

#if defined(__MWERKS__) && defined(macintosh)
char** environ = NULL;
#else
extern char** environ;
#endif

#ifdef __wii__
#include <gccore.h>
#include <wiiuse/wpad.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

void
initWii() {
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

/* Main */

int main(int argc, char* argv[]) {
    coremarkInstance instance;

#if defined(__MWERKS__) && defined(macintosh)
    MaxApplZone();
    MoreMasters();
    MoreMasters();
#endif

#ifdef __wii__
    initWii();
#endif

    coremarkInstantiate(&instance, NULL);

#ifdef __MSL__
    SIOUXSetTitle("\pCoreMark");
#endif
    printf("Benchmarking ...\n");

    if (!wasiInit(argc, argv, environ)) {
        fprintf(stderr, "failed to initialize WASI\n");
        return 1;
    }

    coremark__start(&instance);

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

    return 0;
}
