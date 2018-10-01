#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    m3d::Sprite spr("romfs:/gfx/images.t3x", 0);

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::Input::buttonPressed(m3d::Input::Button::B)) app.exit();

        scr.drawTop(spr); // draw the sprite
        scr.render(); // render the screen
    }

    return 0;
}
