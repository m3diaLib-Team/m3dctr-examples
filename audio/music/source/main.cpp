#include <m3dia.hpp>
#include <iostream>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    // initialize the music
    m3d::Music music("romfs:/bgm.mp3");

    // enable looping
    music.loop(true);

    // start the playback
    music.play();

    std::cout << "Press A to toggle the music-playback!" << '\n';

    // main loop
    while (app.isRunning()) {
        // press B to return to the homebrew menu
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) app.exit();

        // press A to toggle the playback
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::A)) music.togglePlay();
    }

    // the music automatically stops on destruction, so we don't have to call stop() here

    return 0;
}
