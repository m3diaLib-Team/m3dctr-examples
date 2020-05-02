#include <m3dia.hpp>
#include <m3d/graphics/screen.hpp>
#include "vshader_shbin.h"

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;

bool bindShader(){
    C3D_BindProgram(&program);
    return true;
}

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

    // Loading shader
    vshader_dvlb = DVLB_ParseFile((u32*)vshader_shbin, vshader_shbin_size);
    shaderProgramInit(&program);
	shaderProgramSetVsh(&program, &vshader_dvlb->DVLE[0]);

    // Set the background to a blue colour
    screen.setClearColor(m3d::Color(104, 176, 216));

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
        screen.drawTop(teapot, bindShader, m3d::RenderContext::Mode::Spatial);
        // Render the screen
        screen.render();

        // rotate the teapot each frame
        teapot.rotatePitch(1);
        teapot.rotateYaw(1);
        teapot.rotateRoll(1);
    }
    shaderProgramFree(&program);
	DVLB_Free(vshader_dvlb);

    return(0);
}