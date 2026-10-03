#pragma once

#define LOGGER_DEFINE(name) static const char* LOGGER_NAME = name

#define LOGGER_LOG_INFO(...) LoggerLog(        \
    LOGGER_NAME, LOGGER_LEVEL_INFO, __VA_ARGS__ \
)

#define LOGGER_LOG_WARN(...) LoggerLog(        \
    LOGGER_NAME, LOGGER_LEVEL_WARN, __VA_ARGS__ \
)

#define LOGGER_LOG_ERROR(...) LoggerLog(        \
    LOGGER_NAME, LOGGER_LEVEL_ERROR, __VA_ARGS__ \
)

#define LOGGER_LOG_FATAL(...) LoggerLog(        \
    LOGGER_NAME, LOGGER_LEVEL_FATAL, __VA_ARGS__ \
)

typedef enum {
    LOGGER_LEVEL_INFO,
    LOGGER_LEVEL_WARN,
    LOGGER_LEVEL_ERROR,
    LOGGER_LEVEL_FATAL
} LoggerLevel;

void LoggerLog(const char* name, LoggerLevel level, const char* format, ...);
