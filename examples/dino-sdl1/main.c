#include <stdio.h>

#include <SDL.h>

#include "w2c2_base.h"

#if WASM_ENDIAN == WASM_BIG_ENDIAN
#define MEM(o) e_mem->data[e_mem->size - o - 1]
#else
#define MEM(o) e_mem->data[o]
#endif

/* Imports */

F32 Math_random(void) {
    return (F32)rand()/(F32)(RAND_MAX);
}

F32 (*f_Math_random)(void) = &Math_random;

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}


/* Exports */

extern wasmMemory (*e_mem);

extern void (*e_run)();

extern void init();

/* Config */

static const U32 width = 300;
static const U32 height = 75;
static const U32 frameDuration = 1.0 / 60 * 1000;
static const U32 framebufferOffset = 0x5000;

/* Main */

int main(int argc, char* argv[]) {
    /* Initialize module */
    init();

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface *screen = SDL_SetVideoMode(width, height, 32, SDL_DOUBLEBUF | SDL_HWSURFACE);
    if (screen == NULL) {
        fprintf(stderr, "Could not set video mode: %s\n", SDL_GetError());
        return 1;
    }

    SDL_WM_SetCaption("Dino", NULL);

    (*e_run)();

    bool running = false;
    U32 last = SDL_GetTicks();
    U32 rawFrameTime = 0;

#if WASM_ENDIAN == WASM_LITTLE_ENDIAN
    SDL_Surface* offscreen = SDL_CreateRGBSurfaceFrom(
        e_mem->data + 0x5000,
        width,
        height,
        32,
        width * 4,
        0,
        0,
        0,
        0
    );
#endif

    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            bool down = false;

            switch (event.type) {
                case SDL_KEYDOWN:
                    running = true;
                    down = true;
                    break;
                case SDL_KEYUP:
                    break;
                case SDL_QUIT:
                    SDL_Quit();
                    return 0;
            }

            U8 bit = 0;
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    bit = 1;
                    break;
                case SDLK_DOWN:
                    bit = 2;
                    break;
            }

            if (down) {
                MEM(0) |= bit;
            } else {
                MEM(0) &= ~bit;
            }
        }

        if (running) {
            (*e_run)();
        }

#if WASM_ENDIAN == WASM_BIG_ENDIAN
        U8* pixels = (U8*) screen->pixels;
        U32 y = 0;
        for (; y < height; y++) {
            U32 x = 0;
            for (; x < width; x++) {
                U32 pixelOffset = y * (width * 4) + (x * 4);
                U32 memoryOffset = e_mem->size - framebufferOffset - pixelOffset;
                pixels[pixelOffset] = e_mem->data[memoryOffset];
                pixels[pixelOffset + 1] = e_mem->data[memoryOffset - 1];
                pixels[pixelOffset + 2] = e_mem->data[memoryOffset - 2];
                pixels[pixelOffset + 3] = e_mem->data[memoryOffset - 3];
            }
        }
#else
        if (SDL_BlitSurface(offscreen, NULL, screen, NULL) < 0) {
            fprintf(stderr, "Failed to blit: %s\n", SDL_GetError());
            return 1;
        }
#endif

        if (SDL_Flip(screen) < 0) {
            fprintf(stderr, "Failed to flip: %s\n", SDL_GetError());
            return 1;
        }

        U32 now = SDL_GetTicks();
        rawFrameTime = now - last;
        if (rawFrameTime < frameDuration) {
            SDL_Delay(frameDuration - rawFrameTime);
        }
        now = SDL_GetTicks();
        last = now;
    }
}
