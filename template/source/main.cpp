#include <m3dia.hpp>

int main() {
    // instance of the applet
    m3d::Applet app;
    // screen instance that will be used by the console
    m3d::Screen screen;
    // console initialization on the top screen
    consoleInit(GFX_TOP, NULL);

    // standard C printf()
    printf("Hello, world!\n");

    // app's main loop
    while(app.isRunning()) {
        if (m3d::buttons::buttonPressed(m3d::buttons::B)) {
            app.exit();
        }
    }

    return(0);
}