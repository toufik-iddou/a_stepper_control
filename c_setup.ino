void setup(void) {
  // GPIO
  setupPins();
  // Serila monitor
  Serial.begin(9600);
  //interruption
  setupInterrupt();
  //routes
  setupRoutes();
  //stepper
  setupStepper();
  // Initialize PID
  setupPID();
  //init EEPROM size
  EEPROM.begin(MEMORY_SIZE);
  // wifi connection
  setupWifi();
  // MDNS
  setupMDNS();
  // rootes
  server.begin();
  Serial.println("HTTP server started");
// init values and Params from EEPROM
  readDataFromEEPROM(); 
  dispatch();
}


void setupPins(){  
  //GPIO configuration
  pinMode(POWER_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  //GPIO init
  digitalWrite(ENABLE_PIN, LOW);
  digitalWrite(POWER_PIN, HIGH);
  digitalWrite(DIR_PIN, LOW);
}
void setupInterrupt(){
  attachInterrupt(digitalPinToInterrupt(ch1), onChangePosition, CHANGE);
}
void setupRoutes(){
  server.on("/controller",HTTP_GET , handleGetController);
  server.on("/controller",HTTP_POST , handleSetController);
  server.on("/params",HTTP_POST , handleSetParams);
}
void setupStepper(){
    stepper.setMaxSpeed(5000.0);
  stepper.setAcceleration(2500.0);
}
void setupPID(){
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-200, 200); 
}
void setupWifi(){
  WiFi.softAP(ssid, password);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void setupMDNS(){
    if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
}