#include <stdio.h>
#include "logger/logger.h"

LOGGER_DEFINE("Main");

int main() {
    printf(LOGGER_NAME);
    return 0;
}
