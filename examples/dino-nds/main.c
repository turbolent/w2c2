#include <nds.h>

#include "../../w2c2_base.h"
#include "dino.h"

#define INPUT mem->data[0]
#define FP(o) (mem->data[0x5000 + (o)] / 8)

static
F32
Math_random() {
    return (F32)rand()/(F32)(RAND_MAX);
}

static
void*
resolveImport(
    const char* module,
    const char* name
) {
    if (strcmp(module, "Math") == 0
        && strcmp(name, "random") == 0
    ) {
        return (void*)Math_random;
    }

    return NULL;
}

void
trap(
    Trap trap
) {
    abort();
}

static wasmMemory* mem = NULL;
static dinoInstance instance;

void vblank() {
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
                VRAM_A[SCREEN_WIDTH * y + x] = RGB5(31, 31, 31);
            } else {
                int off = (300 * 4) * y + x * 4;
                VRAM_A[SCREEN_WIDTH * y + x] = RGB5(
                    FP(off),
                    FP(off + 1),
                    FP(off + 2)
                );
            }
        }
    }
}

int main(int argc, char* argv[]) {
    dinoInstantiate(&instance, resolveImport);
    mem = dino_mem(&instance);

    powerOn(POWER_ALL_2D);
    vramSetBankA(VRAM_A_LCD);
    videoSetMode(MODE_FB0);
    irqSet(IRQ_VBLANK, vblank);
    lcdSwap();

    while (true) {
        swiWaitForVBlank();
    }
}
