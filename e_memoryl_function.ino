
void writeDataToContorleEEPROM(float p, float i, float d) {
  EEPROM.put(ADDRESS_P, p);
  EEPROM.put(ADDRESS_I, i);
  EEPROM.put(ADDRESS_D, d);
  EEPROM.commit();
}
void writeDataToParamsEEPROM(float a,float f, float ph) {
  EEPROM.put(ADDRESS_A, a);
  EEPROM.put(ADDRESS_F, f);
  EEPROM.put(ADDRESS_PH, ph);
  EEPROM.commit();
}
void readDataFromEEPROM() {
  EEPROM.get(ADDRESS_A,values.a);
  EEPROM.get(ADDRESS_F,values.f);
  EEPROM.get(ADDRESS_PH,values.ph);
  EEPROM.get(ADDRESS_P,pidC.p);
  EEPROM.get(ADDRESS_I,pidC.i);
  EEPROM.get(ADDRESS_D,pidC.d);
}
