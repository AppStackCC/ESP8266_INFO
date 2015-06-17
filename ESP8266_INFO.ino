/**
 * Get ESP8266 infomation.
 * @Author  AppStack.CC
 * @Website http://www.appstack.cc
 */
#include <ESP8266WiFi.h>


void setup()
{
  delay(1000);
  Serial.begin(115200);
  print_info();
}

void loop()
{
	if (Serial.available())  // Wait for keyboard press.
  {
    while (Serial.available())
    {
      char a = Serial.read();
    }

    print_info();
  }

  delay(100);
}

void print_info()
{
  Serial.println("------------------------------------");
  // ESP.getFreeHeap() returns the free heap size.
  Serial.print("FreeHeap : ");
  Serial.println(ESP.getFreeHeap());

  //ESP.getChipId() returns the ESP8266 chip ID as a 32-bit integer.
  Serial.print("Chip ID : ");
  Serial.println(ESP.getChipId());

  //ESP.getFlashChipId() returns the flash chip ID as a 32-bit integer.
  Serial.print("Flash Chip ID : ");
  Serial.println(ESP.getFlashChipId());

  //ESP.getFlashChipSize() returns the flash chip size, in bytes, as seen by the SDK (may be less than actual size).
  Serial.print("Flash Chip Size : ");
  Serial.println(ESP.getFlashChipSize());

  //ESP.getFlashChipSpeed(void) returns the flash chip frequency, in Hz.
  Serial.print("Flash Chip Speed : ");
  Serial.println(ESP.getFlashChipSpeed());

  //ESP.getCycleCount() returns the cpu instruction cycle count since start as an unsigned 32-bit. This is useful for accurate timing of very short actions like bit banging.
  Serial.print("Cycle Count : ");
  Serial.println(ESP.getCycleCount());
}

