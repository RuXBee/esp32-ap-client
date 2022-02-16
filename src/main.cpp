#include "esp_log.h"
#include "config_spiffs.h"
#include "SerialLogger.h"


void setup() {

  delay(1000);
  Serial.println();
  Logger.Info("Initializing program...");
  if(!load_config_json_file()) {
    Logger.Error("Failed load json config file");
  }

}

void loop() {

  yield();

}
