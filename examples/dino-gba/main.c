#include <gba.h>

#include "../../w2c2/w2c2_base.h"
#include "dino.h"

#define INPUT mem->data[0]
#define FP(o) (mem->data[0x5000 + (o)] / 8)

F32
Math__random() {
    return (F32)rand()/(F32)(RAND_MAX);
}

void
trap(
    Trap trap
) {
    abort();
}

int main(int argc, char* argv[]) {
    dinoInstance instance;
    dinoInstantiate(&instance, NULL);
    wasmMemory* mem = dino_mem(&instance);

    /* Set up the interrupt handlers */
    irqInit();

    /* Enable Vblank Interrupt to allow VblankIntrWait */
    irqEnable(IRQ_VBLANK);

    /* Allow Interrupts */
    REG_IME = 1;

    /* Set screen mode & background to display */
    REG_DISPCNT = MODE_3 | BG2_ON;

    dino_run(&instance);

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

        dino_run(&instance);

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
