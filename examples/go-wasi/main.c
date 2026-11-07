#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include "../../w2c2/w2c2_base.h"
#include "../../wasi/wasi.h"
#include "gowasi.h"

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

wasmMemory*
wasiMemory(
    wasmModuleInstance* instance
) {
    return m6_gowasiExport6_memory((m6_gowasiInstance*)instance);
}

extern char** environ;

static void closeSocket(WasiNativeSocket socket) {
#ifdef _WIN32
    closesocket(socket);
#else
    close(socket);
#endif
}

static bool addSockets(U32* listenerFD, U32* clientFD) {
    WasiNativeSocket listener = WASI_INVALID_SOCKET;
    WasiNativeSocket client = WASI_INVALID_SOCKET;
    struct sockaddr_in address;
#ifdef _WIN32
    WSADATA data;
    int length = sizeof(address);
    if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
        return false;
    }
#else
    socklen_t length = sizeof(address);
#endif
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener == WASI_INVALID_SOCKET) {
        goto fail;
    }
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (bind(listener, (struct sockaddr*)&address, sizeof(address)) != 0
        || getsockname(listener, (struct sockaddr*)&address, &length) != 0
        || listen(listener, 1) != 0) {
        goto fail;
    }
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == WASI_INVALID_SOCKET
        || connect(client, (struct sockaddr*)&address, sizeof(address)) != 0) {
        goto fail;
    }
    if (!wasiSocketAdd(listener, WASI_FDFLAGS_NONBLOCK, listenerFD)) {
        goto fail;
    }
    listener = WASI_INVALID_SOCKET;
    if (!wasiSocketAdd(client, WASI_FDFLAGS_NONBLOCK, clientFD)) {
        bool closed = wasiFileDescriptorClose(*listenerFD);
        UNUSED_PARAMETER(closed);
        goto fail;
    }
    return true;
fail:
    if (listener != WASI_INVALID_SOCKET) {
        closeSocket(listener);
    }
    if (client != WASI_INVALID_SOCKET) {
        closeSocket(client);
    }
#ifdef _WIN32
    WSACleanup();
#endif
    return false;
}

/* Main */

int main(int argc, char* argv[]) {
    char listenerArgument[11];
    char clientArgument[11];
    char* arguments[4];
    U32 listenerFD, clientFD;
    UNUSED_PARAMETER(argc);
    arguments[0] = argv[0];
    arguments[1] = listenerArgument;
    arguments[2] = clientArgument;
    arguments[3] = NULL;

    /* Initialize WASI */
    if (!wasiInit(3, arguments, environ)) {
        fprintf(stderr, "failed to init WASI\n");
        return 1;
    }

    if (!wasiFileDescriptorAdd(-1, "/tmp", NULL)) {
        fprintf(stderr, "failed to add preopen\n");
        return 1;
    }

    if (!addSockets(&listenerFD, &clientFD)) {
        fprintf(stderr, "failed to add loopback sockets\n");
        return 1;
    }
    sprintf(listenerArgument, "%u", listenerFD);
    sprintf(clientArgument, "%u", clientFD);

    {
        m6_gowasiInstance instance;
        m6_gowasiInstantiate(&instance, NULL);
        m6_gowasiExport6_X5Fstart(&instance);
        m6_gowasiFreeInstance(&instance);
    }

    return 0;
}
