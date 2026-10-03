#include <stdlib.h>
#include "logger/logger.h"

#define INITIALIZE_OR_RETURN(function) \
    int status = (function)();         \
    if (status != 0) return status

LOGGER_DEFINE("Main");

static int initialize() {
    LOGGER_LOG_INFO("Initialize callback");
    return 1;
}

static int process() {
    LOGGER_LOG_INFO("Process callback");
    return 0;
}

static void terminate() {
    LOGGER_LOG_INFO("Terminate callback");
}

int main() {
    atexit(terminate);

    int status = initialize();
    if (!status) status = process();

    return status;
}
