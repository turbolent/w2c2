#include <stdio.h>

#include <SDL.h>

#include "w2c2_base.h"

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

static const int scale = 2;
static const int width = 300;
static const int height = 75;
static const U32 frameDuration = 1.0 / 60 * 1000;

/* Main */

int main() {
    /* Initialize module */
    init();

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        return 1;
    }

    /* Create window */
    SDL_Window* screen = SDL_CreateWindow(
        "Dino",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width * scale,
        height * scale,
        0
    );
    if (!screen) {
        fprintf(stderr, "Could not create window\n");
        return 1;
    }

    /* Create renderer */
    SDL_Renderer* renderer = SDL_CreateRenderer(
        screen,
        -1,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED
    );
    if (!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }

    /* Create screen texture */
    SDL_Texture* screenTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        width,
        height
    );

    /* Draw initial frame */
    (*e_run)();

    bool running = false;
    U32 last = SDL_GetTicks();
    U32 rawFrameTime = 0;

    while (true) {
        /* Handle events */
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
                    exit(0);
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
                e_mem->data[0] |= bit;
            } else {
                e_mem->data[0] &= ~bit;
            }
        }

        /* Advance game loop */
        if (running) {
            (*e_run)();
        }

        /* Render */
        SDL_RenderClear(renderer);
        SDL_UpdateTexture(screenTexture, NULL, e_mem->data + 0x5000, width * 4);
        SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
        SDL_RenderPresent(renderer);

        /* Limit frame rate */
        U32 now = SDL_GetTicks();
        rawFrameTime = now - last;
        if (rawFrameTime < frameDuration) {
            SDL_Delay(frameDuration - rawFrameTime);
        }
        now = SDL_GetTicks();
        last = now;
    }
}
