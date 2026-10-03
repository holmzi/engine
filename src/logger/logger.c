#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "logger/logger.h"
#include "base/ansi.h"

void LoggerLog(const char* name, LoggerLevel level, const char* format, ...) {
    time_t currentTime = time(NULL);
    struct tm* localTime = localtime(&currentTime);

    const char* color = ANSI_DEFAULT;
    char letter = 'I';
    switch (level) {
        case LOGGER_LEVEL_WARN: color = ANSI_YELLOW; letter = 'W'; break;
        case LOGGER_LEVEL_ERROR: color = ANSI_BRIGHT_RED; letter = 'E'; break;
        case LOGGER_LEVEL_FATAL: color = ANSI_RED; letter = 'F'; break;
    }

    printf(
        "%s[%02d:%02d:%02d/%c/%-8s]: ", color,
        localTime->tm_hour, localTime->tm_min, localTime->tm_sec,
        letter, name
    );

    va_list arguments;
    va_start(arguments, format);
    vprintf(format, arguments);
    va_end(arguments);

    printf("%s\n", ANSI_RESET);
}
