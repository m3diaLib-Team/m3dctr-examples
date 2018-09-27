#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    m3d::Cuboid cube(0.7, 0.7, 0.7);
    consoleInit(GFX_BOTTOM, NULL);

    // create the materials
    m3d::Material mat0;

    m3d::Material mat1;
    mat1.setAmbient(m3d::Color(125, 0, 0));
    mat1.setDiffuse(m3d::Color(255, 0, 125));

    m3d::Material mat2;
    mat2.setAmbient(m3d::Color(125, 125, 0));
    mat2.setDiffuse(m3d::Color(255, 125, 0));

    m3d::Material mat3;
    mat3.setSpecular0(m3d::Color(255, 255, 0));
    mat3.setSpecular1(m3d::Color(60, 60, 0));

    // apply the first material
    cube.setMaterial(mat0);

    std::vector<m3d::Material*> materials;
    materials.push_back(&mat0);
    materials.push_back(&mat1);
    materials.push_back(&mat2);
    materials.push_back(&mat3);

    unsigned int selected = 0;

    printf("Press Left and Right to switch materials\n");

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) app.exit();

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::Left)) {
            if (selected == 0) {
                selected = materials.size() - 1;
            } else {
                selected--;
            }

            cube.setMaterial(*materials[selected]);
        }

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::Right)) {
            if (selected == materials.size() - 1) {
                selected = 0;
            } else {
                selected++;
            }

            cube.setMaterial(*materials[selected]);
        }

        scr.drawTop(cube, m3d::RenderContext::Mode::Spatial); // draw the cube
        scr.render(); // render the screen

        // rotate the cube each frame
        cube.rotatePitch(1);
        cube.rotateYaw(1);
        cube.rotateRoll(1);
    }

    return 0;
}
