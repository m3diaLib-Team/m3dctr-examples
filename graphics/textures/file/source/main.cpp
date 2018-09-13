#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    m3d::Sprite spr;
    m3d::Texture tex;

    // load the texture
    tex.loadFromFile("romfs:/gfx/bean.png");

    // apply the texture
    spr.setTexture(tex);

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) app.exit();

        scr.drawTop(spr); // draw the sprite
        scr.render(); // render the screen
    }

    return 0;
}
