
#ifndef CONFIG_SPIFFS_H
#define CONFIG_SPIFFS_H

#include <SPIFFS.h>
#include <ArduinoJson.h>
#include "FS.h"

bool load_config_json_file(void);

#endif // CONFIG_SPIFFS_H