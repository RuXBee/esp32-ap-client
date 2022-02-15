#include <ArduinoJson.h>
#include "FS.h"
#include <SPIFFS.h>

bool load_config_json_file() {
  // Initialize SPIFFS SPI bus
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return false;
  } 
  // Load config file as read
  File configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
    Serial.print("FAiled to open json file");
    return false;
  } 
  // Check json file size
  size_t size = configFile.size();
  Serial.print("Size:");
  Serial.println(size);
  if (size > 1024) {
    Serial.println("json file too large");
    return false;
  }
  // Define smart pointer for json file read
  std::unique_ptr <char[]> buf(new char[size]);
  configFile.readBytes(buf.get(), size);
  Serial.println(buf.get());
  // Define doc with parse json file
  StaticJsonDocument<1024> doc; // document json object
  auto error = deserializeJson(doc, buf.get());
  if (error) {
    Serial.print(F("deserializeJson() failed with code "));
    Serial.println(error.c_str());
  }
  // Create variables of json file fields 
  String ssid = doc["ssid"];
  String pwd = doc["pwd"];
  return true;
}


void setup() {
  Serial.begin(9600);
  delay(1000);

  if(!load_config_json_file()) {
    Serial.println("Failed load json config file");
  }

}

void loop() {

}