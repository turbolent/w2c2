#include <gba.h>

#include "../../w2c2_base.h"

#define INPUT e_mem->data[0]
#define FP(o) (e_mem->data[0x5000 + (o)] / 8)

/* Imports */

F32 Math_random(void) {
    return (F32)rand()/(F32)(RAND_MAX);
}

F32 (*f_Math_random)(void) = &Math_random;

void
trap(
    Trap trap
) {
    abort();
}


/* Exports */

extern wasmMemory (*e_mem);

extern void (*e_run)();

extern void init();

/* Config */
/*
void vblankInterrupt() {
    scanKeys();

    (*e_run)();

}*/

int main(int argc, char* argv[]) {

    /* Set up the interrupt handlers */
    irqInit();

/*
    irqSet(IRQ_VBLANK, vblankInterrupt);
*/

    /* Enable Vblank Interrupt to allow VblankIntrWait */
    irqEnable(IRQ_VBLANK);

    /* Allow Interrupts */
    REG_IME = 1;

    /* Set screen mode & background to display */
    REG_DISPCNT = MODE_3 | BG2_ON;

    /* Initialize module */
    init();

    (*e_run)();

    while (true) {
        scanKeys();

        int current = keysUp();
        if (current & KEY_A) {
            INPUT &= ~1;
        }
        if (current & KEY_DOWN) {
            INPUT &= ~2;
        }

        int down = keysDown();
        if (down & KEY_A) {
            INPUT |= 1;
        }
        if (down & KEY_DOWN) {
            INPUT |= 2;
        }

        (*e_run)();

        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                if (y >= 75) {
                    ((u16*)(VRAM))[SCREEN_WIDTH * y + x] = RGB5(31, 31, 31);
                } else {
                    int off = (300 * 4) * y + x * 4;
                    ((u16*)(VRAM))[SCREEN_WIDTH * y + x] = RGB5(
                        FP(off),
                        FP(off + 1),
                        FP(off + 2)
                    );
                }
            }
        }

        VBlankIntrWait();
    }
}
