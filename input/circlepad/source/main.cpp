#include <m3dia.hpp>

void printAt(int t_x, int t_y, const std::string& t_text) {
    printf("\x1b[%d;%dH%s\n", t_y, t_x, t_text.c_str());
}

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    // main loop
    while (app.isRunning()) {
        // press B or Start to return to the homebrew menu
        if (m3d::Input::buttonPressed(m3d::Input::Button::Start)) app.exit();
        if (m3d::Input::buttonPressed(m3d::Input::Button::B)) app.exit();

        printAt(0, 1, "Circlepad position: "
                "{X: " + std::to_string(m3d::circlepad::getXPosition()) +
                ", Y: " + std::to_string(m3d::circlepad::getYPosition()) + "}");

        scr.render(); // render the screen
    }

    return 0;
}
