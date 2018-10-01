#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    m3d::Cuboid cube(0.5, 0.5, 0.5), cube2(0.3, 0.3, 0.3);
    cube.moveX(-0.5);
    cube2.moveX(0.5);

    printf("Use the circlepad to move around\n");
    printf("Use the DPad or the C-Stick to look around");

    m3d::Camera& cam = scr.getCamera(m3d::RenderContext::ScreenTarget::Top);

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::Input:::buttonPressed(m3d::Input:::Button::B)) app.exit();

        if (m3d::Input:::buttonDown(m3d::Input:::Button::DPadLeft)) cam.rotateYaw(-1);
        if (m3d::Input:::buttonDown(m3d::Input:::Button::DPadRight)) cam.rotateYaw(1);

        if (m3d::Input:::buttonDown(m3d::Input:::Button::DPadUp)) cam.rotatePitch(-1);
        if (m3d::Input:::buttonDown(m3d::Input:::Button::DPadDown)) cam.rotatePitch(1);

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CStickLeft)) cam.rotateYaw(-1);
        if (m3d::Input:::buttonDown(m3d::Input:::Button::CStickRight)) cam.rotateYaw(1);

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CStickUp)) cam.rotatePitch(-1);
        if (m3d::Input:::buttonDown(m3d::Input:::Button::CStickDown)) cam.rotatePitch(1);

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CPadUp)) {
            float dirX = -std::sin(cam.getYaw(true)) * 0.03;
            float dirZ = std::cos(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CPadDown)) {
            float dirX = std::sin(cam.getYaw(true)) * 0.03;
            float dirZ = -std::cos(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        };

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CPadLeft)) {
            float dirX = std::cos(cam.getYaw(true)) * 0.03;
            float dirZ = std::sin(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }

        if (m3d::Input:::buttonDown(m3d::Input:::Button::CPadRight)) {
            float dirX = -std::cos(cam.getYaw(true)) * 0.03;
            float dirZ = -std::sin(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }

        scr.drawTop(cube, m3d::RenderContext::Mode::Spatial); // draw the cube
        scr.drawTop(cube2, m3d::RenderContext::Mode::Spatial); // draw the cube
        scr.render(); // render the screen
    }

    return 0;
}
