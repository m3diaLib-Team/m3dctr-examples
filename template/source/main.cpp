#include <m3dia.hpp>

int main() {
    m3d::Applet app;
    m3d::Input input;
    m3d::Screen screen;
    m3d::Console console = m3d::Console(m3d::RenderContext::ScreenTarget::Top); // init console on the top screen

    console << "Hello, World!" << m3d::Console::Endl;

    while(app.isRunning()) {
        if (input.buttonPressed(input.Start)) {
            app.exit();
        }
    }

    return(0);
}