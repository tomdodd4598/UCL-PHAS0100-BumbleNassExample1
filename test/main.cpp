#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "main.hpp"

namespace test {
    int argc;
    char** argv;
}

int main(int argc, char** argv) {
    test::argc = argc;
    test::argv = argv;
    
    Catch::Session session;

    // writing to session.configData() here sets defaults
    // this is the preferred way to set them

    /*int return_code = session.applyCommandLine(argc, argv);
    if (return_code != 0) {
        return return_code;
    }*/

    // writing to session.configData() or session.Config() here
    // overrides command line args
    // only do this if you know you need to
    
    int num_failed = session.run();

    // numFailed is clamped to 255 as some unices only use the lower 8 bits
    // This clamping has already been applied, so just return it here
    // You can also do any post run clean-up here
    
    return num_failed;
}
