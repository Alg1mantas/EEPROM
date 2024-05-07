#include <Wire.h>

#define EEPROM_ADRRESS 0x50

void setup() {
  Serial.begin(9600);
  Wire.begin();
  for (int i = 0; i <= 1023; i++) {
    Serial.print("address: 0x");
    Serial.print(String(i, HEX));
    Serial.print(" value: ");
    Serial.println(String(read(EEPROM_ADRRESS, byte(i)), HEX));
  }
}

void loop() {

}

byte read(byte EEPROM_ADDRESS, byte dataAddress) {
  Wire.beginTransmission(EEPROM_ADDRESS);
  Wire.write(dataAddress);
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_ADDRESS, dataAddress);
  if (Wire.available()) {
    return Wire.read();
  }

  return 0;
}

