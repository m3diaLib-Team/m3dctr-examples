#include <m3dia.hpp>

int main() {
    // Initialize everything
    m3d::Applet app;
    m3d::Screen screen;
    m3d::Texture tex;
    m3d::Model teapot;

    consoleInit(GFX_BOTTOM, NULL);

    printf("Loading teapot...\n");

    // Load the teapot model
    teapot.loadFromFile("romfs:/teapot.obj");

    printf("Loading texture...\n");

    // load the texture
    tex.loadFromFile("romfs:/texture.png");

    // bind the texture
    teapot.bindTexture(tex);

    // Scale the teapot so that it will fit in the viewport
    teapot.setScale(0.2f, 0.2f, 0.2f);

    printf("Press A to toggle the texture");

    // app's main loop
    while(app.isRunning()) {
        if (m3d::buttons::buttonPressed(m3d::buttons::B)) {
            app.exit();
        }

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::A)) {
            if (teapot.isTextureBound()) {
                teapot.unbindTexture();
            } else {
                teapot.bindTexture(tex);
            }
        }

        // Draw the teapot to the top screen
        screen.drawTop(teapot, m3d::RenderContext::Mode::Spatial);
        // Render the screen
        screen.render();

        // rotate the teapot each frame
        teapot.rotatePitch(1);
        teapot.rotateYaw(1);
        teapot.rotateRoll(1);
    }

    return(0);
}