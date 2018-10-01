#include <m3dia.hpp>

int main() {
    m3d::Applet app;
    m3d::Input input;
    m3d::Screen screen;
    consoleInit(GFX_TOP, NULL);

    printf("Hello, world!\n");

    while(app.isRunning()) {
        if (input.buttonPressed(input.B)) {
            app.exit();
        }
    }

    return(0);
}