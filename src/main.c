#include "logger/logger.h"

LOGGER_DEFINE("Main");

int main() {
    LOGGER_LOG_INFO("Hello World!");
    return 0;
}
