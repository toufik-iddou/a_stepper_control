
void writeDataToEEPROM(char mode,float V,float R,float TSR,float theta) {
  EEPROM.put(ADDRESS_MODE, mode);
  EEPROM.put(ADDRESS_V, V);
  EEPROM.put(ADDRESS_R, R);
  EEPROM.put(ADDRESS_TSR, TSR);
  EEPROM.put(ADDRESS_THETA, theta);
  EEPROM.commit();
}

MyValues readDataFromEEPROM() {
  EEPROM.get(ADDRESS_MODE, values.mode);
  EEPROM.get(ADDRESS_V, values.V);
  EEPROM.get(ADDRESS_R, values.R);
  EEPROM.get(ADDRESS_TSR, values.TSR);
  EEPROM.get(ADDRESS_THETA, values.theta);
  return values;
  
}
