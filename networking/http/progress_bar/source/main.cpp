#include <m3dia.hpp>

int main() {
    // initialize everything
    m3d::Applet app;
    m3d::Input input;
    m3d::Console cons;
    cons.useScreen(m3d::RenderContext::ScreenTarget::Bottom);

    // create the client
    m3d::HTTPClient client;

    // perform the request
    // HTTPS is supported as well
    client.getAsync("http://ipv4.download.thinkbroadband.com/5MB.zip");

    bool finished = false;

    // main loop
    while (app.isRunning()) {
        // press Start to return to the homebrew menu
        if (input.buttonPressed(input.Start)) app.exit();

        // check if the client is finished
        if (client.isFinished() && !finished) {
            finished = true; // we only want this to execute once

            if (client.getStatus() == client.Status::OK) {
                cons << "Download finished!";
            } else {
                cons << "The request failed due to an error";
            }
        } else {
            // if the request is still running, display the progress bar
            int length = std::floor(38.0 * client.getProgress());
            std::string bar;

            for (int i = 0; i < 38; i++) {
                bar += (i < length ? '=' : ' ');
            }

            cons << cons.position(1, 1) << "[" << bar << "]";

            // display progress information
            cons << cons.position(1, 2)
                 << std::to_string(client.getProgressSize()) << " Bytes downloaded"
                 << cons.Endl
                 << std::to_string(client.getTotalSize()) << " Bytes total";
        }
    }

    // all running requests automatically get canceled on destruction

    return 0;
}
