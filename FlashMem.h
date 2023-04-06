#include "Arduino.h"
#include <EEPROM.h>
#define EEPROM_SIZE 8190


void writeStringToEEPROM(int addrOffset, const String &strToWrite)
{
  byte len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
  }
}

String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\0'; 
  return String(data);
}

void writeSingle(int addrOffset, byte write){
EEPROM.write(addrOffset, write);
}


byte readSingle(int addrOffset){
  byte returnByte = EEPROM.read(addrOffset);
  return returnByte;
}

void setupFlash()
{
  
  Serial.println("start Flash...");
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM");
    
  }

}

//https://roboticsbackend.com/arduino-write-string-in-eeprom/#Write_the_String 