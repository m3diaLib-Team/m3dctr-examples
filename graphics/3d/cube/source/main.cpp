#include <m3dia.hpp>

using namespace m3d;

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    m3d::Texture tex;
    //m3d::Cuboid cube(0.7, 0.7, 0.7);
	//Circle circle(4, 4, 10, Color(0, 0, 255));
	//Rectangle rect(80, 80, 50, 75, Color(0, 255, 0));
	//Polygon p(20, 20, 20);
	
    consoleInit(GFX_BOTTOM, NULL);

    printf("Press A to toggle the texture");

    // load the texture
    tex.loadFromFile("romfs:/gfx/texture.png");

    // bind the texture
    //cube.bindTexture(tex);

	
    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
		/*
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) app.exit();

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::A)) {
            if (cube.isTextureBound()) {
                cube.unbindTexture();
            } else {
                cube.bindTexture(tex);
            }
        }

        scr.drawTop(cube, m3d::RenderContext::Mode::Spatial); // draw the cube
		*/
		//scr.drawTop(rect, RenderContext::Mode::Flat);
        scr.render(); // render the screen

		/*
        // rotate the cube each frame
        cube.rotatePitch(1);
        cube.rotateYaw(1);
        cube.rotateRoll(1);
		*/
    }

    return 0;
}
