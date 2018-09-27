#include <m3dia.hpp>

void printAt(int t_x, int t_y, const std::string& t_text) {
    printf("\x1b[%d;%dH%s\n", t_y, t_x, t_text.c_str());
}

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    unsigned int selected = 0;

    // alarm
    m3d::LEDPattern pattern0;
    pattern0.addKeyFrame(0, m3d::Color(255, 0, 0));
    pattern0.addKeyFrame(15, m3d::Color(0, 0, 0));
    pattern0.addKeyFrame(31, m3d::Color(255, 0, 0));
    pattern0.setTime(3);

    // "warning" (alternating between red and yellow)
    m3d::LEDPattern pattern1;
    pattern1.addKeyFrame(0, m3d::Color(255, 0, 0));
    pattern1.addKeyFrame(15, m3d::Color(255, 255, 0));
    pattern1.addKeyFrame(31, m3d::Color(255, 0, 0));
    pattern1.setTime(1.5);

    // rainbow
    m3d::LEDPattern pattern2;
    pattern2.addKeyFrame(0, m3d::Color(255, 0, 0));
    pattern2.addKeyFrame(4, m3d::Color(255, 125, 0));
    pattern2.addKeyFrame(8, m3d::Color(255, 255, 0));
    pattern2.addKeyFrame(12, m3d::Color(0, 255, 0));
    pattern2.addKeyFrame(16, m3d::Color(0, 255, 255));
    pattern2.addKeyFrame(20, m3d::Color(0, 0, 255));
    pattern2.addKeyFrame(25, m3d::Color(125, 0, 255));
    pattern2.setTime(5);

    // red blinking
    m3d::LEDPattern pattern3;
    pattern3.addKeyFrame(0, m3d::Color(255, 0, 0));
    pattern3.addKeyFrame(3, m3d::Color(0, 0, 0), true);
    pattern3.addKeyFrame(8, m3d::Color(255, 0, 0), true);
    pattern3.addKeyFrame(11, m3d::Color(0, 0, 0), true);
    pattern3.addKeyFrame(16, m3d::Color(255, 0, 0), true);
    pattern3.addKeyFrame(19, m3d::Color(0, 0, 0), true);
    pattern3.setTime(1.5);

    // green sawtooth
    m3d::LEDPattern pattern4;
    pattern4.addKeyFrame(0, m3d::Color(0, 255, 0));
    pattern4.addKeyFrame(31, m3d::Color(0, 0, 0));
    pattern4.setTime(3);

    // blue-green alternating
    m3d::LEDPattern pattern5(m3d::Color(0, 0, 255));
    pattern5.addKeyFrame(14, m3d::Color(0, 0, 255));
    pattern5.addKeyFrame(15, m3d::Color(0, 255, 0), true);
    pattern5.setTime(1.5);

    // constant white
    m3d::LEDPattern pattern6;
    pattern6.addKeyFrame(0, m3d::Color(255, 255, 255));
    pattern6.setTime(1.5);

    std::vector<m3d::LEDPattern> patterns;
    patterns.push_back(pattern0);
    patterns.push_back(pattern1);
    patterns.push_back(pattern2);
    patterns.push_back(pattern3);
    patterns.push_back(pattern4);
    patterns.push_back(pattern5);
    patterns.push_back(pattern6);

    // main loop
    while (app.isRunning()) {
        // press Start to return to the homebrew menu
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::Start)) app.exit();

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::Up)) {
            if (selected < patterns.size() - 1) {
                selected++;
            } else {
                selected = 0;
            }
        }

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::Down)) {
            if (selected > 0) {
                selected--;
            } else {
                selected = patterns.size() - 1;
            }
        }

        if (m3d::buttons::buttonPressed(m3d::buttons::Button::A)) patterns[selected].play();
        if (m3d::buttons::buttonPressed(m3d::buttons::Button::B)) m3d::LEDPattern::stop();

        printAt(0, 1, m3d::LEDPattern::isPlaying() ? "Playing    " : "Not playing");
        printAt(0, 2, "Press A to start playing the selected\npattern");
        printAt(0, 4, "Press B to stop playing");
        printAt(0, 5, "Currently selected pattern: " + std::to_string(selected));
        printAt(0, 6, "Press up/down to change the pattern");

        scr.render(); // render the screen
    }

    return 0;
}
