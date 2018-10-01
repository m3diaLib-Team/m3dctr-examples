#include <m3dia.hpp>

void validator(m3d::SoftwareKeyboard::KeyboardEvent& t_evt) {
    printf("Validating\n");
    if (t_evt.getText() == "lenny") {
        t_evt.error("What did you expect? I'm not fincs.");
    } else if (t_evt.getText() == "brick") {
        t_evt.close("I think you're confusing the\nexamples.");
    } else {
        t_evt.valid();
    }
}

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Screen scr;
    consoleInit(GFX_BOTTOM, NULL);

    m3d::SoftwareKeyboard keyboardNormal, keyboardNumpad, keyboardValidating, passwordKeyboard;

    keyboardNormal.setHintText("Type something");

    keyboardNumpad.setKeyboardType(m3d::SoftwareKeyboard::KeyboardType::Numpad);
    keyboardNumpad.setFixedLength(5);

    keyboardValidating.setValidator(validator);

    passwordKeyboard.setPasswordMode(m3d::SoftwareKeyboard::PasswordMode::Delay);

    printf("Press Up to launch a normal keyboard\n");
    printf("Press Left to launch a numpad\n");
    printf("Press Right to launch a validating keyboard\n");
    printf("Press Down to launch a password keyboard\n");

    // main loop
    while (app.isRunning()) {
        // press B or Start to return to the homebrew menu
        if (m3d::Input::buttonPressed(m3d::Input::Button::Start)) app.exit();
        if (m3d::Input::buttonPressed(m3d::Input::Button::B)) app.exit();

        if (m3d::Input::buttonPressed(m3d::Input::Button::Up)) {
            keyboardNormal.display();
            printf("Entered text: %s\n", keyboardNormal.getLastInput().c_str());
        }

        if (m3d::Input::buttonPressed(m3d::Input::Button::Left)) {
            keyboardNumpad.display();
            printf("Entered text: %s\n", keyboardNumpad.getLastInput().c_str());
        }

        if (m3d::Input::buttonPressed(m3d::Input::Button::Right)) {
            keyboardValidating.display();
            printf("Entered text: %s\n", keyboardValidating.getLastInput().c_str());
        }

        if (m3d::Input::buttonPressed(m3d::Input::Button::Down)) {
            passwordKeyboard.display();
            printf("Entered text: %s\n", passwordKeyboard.getLastInput().c_str());
        }

        scr.render(); // render the screen
    }

    return 0;
}
