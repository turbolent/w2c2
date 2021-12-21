#import <Cocoa/Cocoa.h>
#import "DinoView.h"
#import "AppDelegate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSApplication *application = [NSApplication sharedApplication];

        AppDelegate *delegate = [AppDelegate new];
        [application setDelegate:delegate];

        NSMenu *subMenu = [NSMenu new];
        NSMenuItem *quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit"
                                                              action:@selector(terminate:)
                                                       keyEquivalent:@"q"];

        [subMenu addItem:quitMenuItem];

        NSMenu *menu = [NSMenu new];
        NSMenuItem *appMenuItem = [NSMenuItem new];
        [appMenuItem setSubmenu:subMenu];
        [menu addItem:appMenuItem];

        application.mainMenu = menu;

        NSWindow *window =
            [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, width * scale, height * scale)
                                        styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable
                                          backing:NSBackingStoreBuffered
                                                defer:NO];
        window.contentView = [DinoView new];
        [window setTitle:@"Dino"];
        [window center];
        [window makeKeyAndOrderFront:nil];
        [NSApp activateIgnoringOtherApps:YES];
        [NSApp run];
    }
    return 0;
}
