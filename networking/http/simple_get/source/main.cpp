#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Input input;
    m3d::Console cons;
    cons.useScreen(m3d::RenderContext::ScreenTarget::Bottom);

    // create the client and the response buffer
    m3d::HTTPClient client;
    std::string response;

    // perform the request
    // HTTPS is supported as well
    response = client.get("http://techslides.com/demos/samples/sample.txt");

    if (client.getStatus() == client.Status::OK) {
        cons << client.getResponse() << cons.Endl;
    } else {
        cons << "The request failed due to an error";
    }

    // main loop
    while (app.isRunning()) {
        // press Start to return to the homebrew menu
        if (input.buttonPressed(input.Start)) app.exit();
    }

    return 0;
}
