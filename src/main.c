#include <stdlib.h>
#include "storage/storage.h"
#include "logger/logger.h"

#define INITIALIZE_OR_RETURN(function) \
    int status = function();           \
    if (status != 0) return status

LOGGER_DEFINE("Main");

static int initialize() {
    INITIALIZE_OR_RETURN(StorageInitialize);
    return 0;
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
