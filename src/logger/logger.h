#pragma once

#define LOGGER_DEFINE(name) static const char* LOGGER_NAME = name;

#define LOGGER_LOG_INFO(...) Logger_log(LOGGER_NAME, __VA_ARGS__);

#define LOGGER_LOG_WARN(...) Logger_log(LOGGER_NAME, __VA_ARGS__);

#define LOGGER_LOG_ERROR(...) Logger_log(LOGGER_NAME, __VA_ARGS__);

void Logger_log(const char* name, ...);
