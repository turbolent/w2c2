#import <appkit/appkit.h>
#include <stdio.h>

#include "../../../w2c2/w2c2_base.h"
#include "dino.h"

#define MEM(o) mem->data[mem->size - (o) - 1]

/* Imports */

F32
Math__random() {
    return (F32)rand()/(F32)(RAND_MAX);
}

void
trap(
    Trap trap
) {
    fprintf(stderr, "TRAP: %s\n", trapDescription(trap));
    abort();
}

/* Exports */

static wasmMemory* mem = NULL;
static dinoInstance instance;

/* Config */

static const int width = 300;
static const int height = 75;
//static const NSTimeInterval frameDuration = 1.0 / 60;
static const U32 framebufferOffset = 0x5000;

/* Globals */

static U8* bitmap;
static U8* framebuffer;
static int framebufferSize;


/* View */

@interface DinoView: View

DPSTimedEntry timedEntry;
BOOL space, down;

@end

@implementation DinoView

void step(DPSTimedEntry timedEntry, double now, void *view) {
    NXEvent *event = NULL;
    DinoView *dinoView = view;
    while (event = [NXApp peekAndGetNextEvent:NX_KEYUPMASK | NX_KEYDOWNMASK]) {
        switch (event->type) {
        case NX_KEYUP:
            [dinoView keyUp:event];
            break;
        case NX_KEYDOWN:
            [dinoView keyDown:event];
            break;
        }
    }
    [dinoView display];
}

- initFrame:(const NXRect *)frameRect
{
    [super initFrame:frameRect];

    timedEntry = DPSAddTimedEntry(0.0, &step, self, NX_MODALRESPTHRESHOLD);

    return self;
}

- free
{
    DPSRemoveTimedEntry(timedEntry);
    return [super free];
}

- drawSelf:(const NXRect *)rects :(int)rectCount
{
    int x, y;

    printf("# %d %d\n", space, down);

    if (space) {
        MEM(0) |= 1;
    } else {
        MEM(0) &= ~1;
    }

    if (down) {
        MEM(0) |= 2;
    } else {
        MEM(0) &= ~2;
    }

    dino_run(&instance);

    for (y = 0; y < height; y++) {       
        for (x = 0; x < width; x++) {
            int alphaOffset = y * width * 4 + x * 4 + 3;
            bitmap[y * width + x] = framebuffer[framebufferSize - alphaOffset];
        }
    }

    NXDrawBitmap(rects, width, height, 8, 1, 8, width, NO, NO, NX_RGBColorSpace, &bitmap);

    return self;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- keyDown:(NXEvent *)event
{
    printf("DOWN: %d\n", event->data.key.charCode);
    switch (event->data.key.charCode) {
        case 175:
            down = YES;
            break;
        case 32:
            space = YES;
            break;
    }
    return [super keyDown:event];
}

- keyUp:(NXEvent *)event
{
    printf("UP: %d\n", event->data.key.charCode);
    switch (event->data.key.charCode) {
        case 175:
            down = NO;
            break;
        case 32:
            space = NO;
            break;
    }
    return [super keyUp:event];
}


@end

/* main */

void main(int argc, char *argv[]) {
    Window *window;
    NXRect windowRect;
    Menu *mainMenu;
    DinoView *dinoView;
    NXRect bounds;

    dinoInstantiate(&instance, NULL);
    mem = dino_mem(&instance);

    framebufferSize = width * 4 * height;
    bitmap = malloc(width * height);
    framebuffer = mem->data + mem->size - framebufferOffset - framebufferSize;

    dino_run(&instance);

    [Application new];

    NXSetRect(&windowRect, 0, 0, width * 2, height * 2);
    bounds = windowRect;

    window = 
      [Window newContent:&windowRect
                   style:NX_TITLEDSTYLE
                 backing:NX_RETAINED
              buttonMask:NX_CLOSEBUTTONMASK
                   defer:NO];
    [window setTitle:"Dino"];
    [window center];
    [window display];
    [window makeKeyAndOrderFront:nil];

    mainMenu = [Menu newTitle:"Dino"];
    [mainMenu addItem:"Quit"
               action:@selector(terminate:)
            keyEquivalent:'q'];
    [mainMenu sizeToFit];
    [NXApp setMainMenu:mainMenu];

    dinoView = [DinoView newFrame:&bounds];
    [[window setContentView:dinoView] free];
    [dinoView display];

    [NXApp run];    
    [NXApp free];

    free(bitmap);

    exit(0);
}
