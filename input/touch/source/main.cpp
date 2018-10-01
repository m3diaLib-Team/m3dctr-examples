#include <m3dia.hpp>

void printAt(int t_x, int t_y, const std::string& t_text) {
    printf("\x1b[%d;%dH%s\n", t_y, t_x, t_text.c_str());
}

int main() {
    m3d::Applet app;
    m3d::Screen scrn;
    m3d::Input inp;
    consoleInit(GFX_TOP, NULL);

    while(app.isRunning()) {
        if (inp.buttonPressed(inp.B)) {
            app.exit();
        }
        printAt(0, 1, "Touch position: "
                "{X: " + std::to_string(inp.getTouchX()) +
                ", Y: " + std::to_string(inp.getTouchY()) + "}          ");
    }

    return(0);
}