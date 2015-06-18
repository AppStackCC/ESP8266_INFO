/**
 * Get ESP8266 infomation.
 * @Author  AppStack.CC
 * @Website http://www.appstack.cc
 */
 
#include <ESP8266WiFi.h>

// Thank K.Settakan Suwannawat for explain flash chip id. https://www.facebook.com/groups/ChiangMaiMakerClub/permalink/781221611997934/
// Find flash chip from http://code.coreboot.org/svn/flashrom/trunk/flashchips.h 

const long FlashID[3]     =  {0x1640EF,0x1340C8,0x1340EF}; // Little Endian
const String FlashDesc[3] =  {"WINBOND W25Q32: 32M-bit / 4M-byte","GIGADEVICE GD25Q40 4M-bit / 512K-byte","WINBOND W25Q40 4M-bit / 512K-byte"};

void setup()
{
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
  Serial.print("Flash Chip ID : 0x");
  Serial.print(ESP.getFlashChipId(),HEX);
  Serial.print(" - ");

  for(int i=0 ; i < 3 ; i++)
  {
    if (ESP.getFlashChipId() == FlashID[i])
    {
      Serial.println(FlashDesc[i]);
      goto next_val;
    }
  }
  Serial.println("Unknown flash chip");
  
  next_val:
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

