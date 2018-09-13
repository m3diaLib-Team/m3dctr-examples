#include <m3dia.hpp>
#include <iostream>

void threadFunc(m3d::Parameter param) {
    int id = param.get<int>();

    while (true) {
        std::cout << "I'm thread #" << std::to_string(id) << "!" << '\n';
        m3d::Thread::sleep(1000 * id); // wait; also, this is needed to allow for concurrency (refer to the documentation for m3d::Thread::sleep())
    }
}

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    // create our two threads
    m3d::Thread t1(threadFunc, 1),
                t2(threadFunc, 2);

    // start the threads
    t1.start();
    t2.start();

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) app.exit();
    }

    // threads automatically join on destruction, so there's no need to call m3d::Thread::join() here

    return 0;
}
