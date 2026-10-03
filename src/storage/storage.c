#include "storage/storage.h"
#include "logger/logger.h"

LOGGER_DEFINE("Storage");

int StorageInitialize() {
    LOGGER_LOG_INFO("StorageInitialize callback");
    return 0;
}

void StorageTerminate() {}
