
#include "../../w2c2_base.h"

#import "DinoView.h"
#include "dino.h"

#define MEM(o) mem->data[o]

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
) {}

static wasmMemory* mem = NULL;
static dinoInstance instance;

/* Config */

static const NSTimeInterval frameDuration = 1.0 / 60;
static const U32 framebufferOffset = 0x5000;

/* View */

@interface DinoView ()

@property (strong) NSTimer *redrawTimer;
@property (strong) NSBitmapImageRep *image;
@property (assign) BOOL space;
@property (assign) BOOL down;

@end

@implementation DinoView

- (instancetype)init
{
    if (self = [super init]) {

        [self setSpace:NO];
        [self setDown:NO];

        dinoInstantiate(&instance, resolveImport);
        mem = dino_mem(&instance);

        self.image = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:NULL
                                                             pixelsWide:width
                                                             pixelsHigh:height
                                                          bitsPerSample:8
                                                        samplesPerPixel:4
                                                               hasAlpha:YES
                                                               isPlanar:NO
                                                         colorSpaceName:NSCalibratedRGBColorSpace
                                                           bitmapFormat:0
                                                            bytesPerRow:width * 4
                                                           bitsPerPixel:0];

        self.redrawTimer = [NSTimer scheduledTimerWithTimeInterval:frameDuration
                                                            target:self
                                                          selector:@selector(step)
                                                          userInfo:nil
                                                           repeats:YES];
    }
    return self;
}

- (void)step
{
    if ([self space]) {
        MEM(0) |= 1;
    } else {
        MEM(0) &= ~1;
    }

    if ([self down]) {
        MEM(0) |= 2;
    } else {
        MEM(0) &= ~2;
    }

    dino_run(&instance);

    [self setNeedsDisplay:YES];
}

- (void)drawRect:(NSRect)dirtyRect
{
    [super drawRect:dirtyRect];

    memcpy(self.image.bitmapData,
           mem->data + framebufferOffset,
           width * 4 * height);

    [self.image drawInRect:[self bounds]];
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (void)keyDown:(NSEvent *)event
{
    switch ([event keyCode]) {
        case 125:
            [self setDown:YES];
            break;
        case 49:
            [self setSpace:YES];
            break;
        default:
            [super keyUp:event];
            break;
    }
}

- (void)keyUp:(NSEvent *)event
{
    switch ([event keyCode]) {
        case 125:
            [self setDown:NO];
            break;
        case 49:
            [self setSpace:NO];
            break;
        default:
            [super keyUp:event];
            break;
    }
}

@end
