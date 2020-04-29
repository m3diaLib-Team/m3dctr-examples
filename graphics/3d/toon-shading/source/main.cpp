#include <m3dia.hpp>
#include "vshader_shbin.h"

static DVLB_s* vshader_dvlb;
static shaderProgram_s program;
// static int uLoc_projection, uLoc_modelView;
// static C3D_Mtx projection;
// static C3D_Light light;

static float angleX = 0.0, angleY = 0.0;

bool toonShade(){
    C3D_BindProgram(&program);
    // C3D_FVec objPos   = FVec4_New(0.0f, 0.0f, -3.0f, 1.0f);
    // C3D_FVec lightPos = FVec4_New(0.0f, 0.0f, -0.5f, 1.0f);

    // // Calculate the modelView matrix
    // C3D_Mtx modelView;
    // Mtx_Identity(&modelView);
    // Mtx_Translate(&modelView, objPos.x, objPos.y, objPos.z, true);
    // Mtx_RotateX(&modelView, C3D_Angle(sinf(angleX)/4), true);
    // Mtx_RotateY(&modelView, C3D_Angle(angleY), true);
    // Mtx_Translate(&modelView, 0.0f, -0.5f, 0.f, true);

    // C3D_LightPosition(&light, &lightPos);

    // // Update the uniforms
    // C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_projection, &projection);
    // C3D_FVUnifMtx4x4(GPU_VERTEX_SHADER, uLoc_modelView,  &modelView);
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
    // Get the location of the uniforms
	uLoc_projection   = shaderInstanceGetUniformLocation(program.vertexShader, "projection");
	uLoc_modelView    = shaderInstanceGetUniformLocation(program.vertexShader, "modelView");

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
        screen.drawTop(teapot, toonShade, m3d::RenderContext::Mode::Spatial);
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