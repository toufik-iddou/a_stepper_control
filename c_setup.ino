
void setup(void) {
  // GPIO
  pinMode(0, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  digitalWrite(DIR_PIN, LOW);
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  Serial.begin(9600);
  //interruption
  attachInterrupt(digitalPinToInterrupt(ch1), onChangePosition, CHANGE);
  ITimer1.attachInterruptInterval(TIMER1_INTERVAL_MS * 1000, movementInterruption);
  //stepper
  stepper.setMaxSpeed(5000.0);
  stepper.setAcceleration(2500.0);
   // Initialize PID
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-200, 200);  // Adjust based on your motor and driver
  //init EEPROM size
  EEPROM.begin(MEMORY_SIZE);
  // wifi connection
   WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // MDNS
  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }
  // rootes
  server.on("/",HTTP_GET, handleGetHome);
  server.on("/",HTTP_POST, handlePostHome);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
// init values
  values = readDataFromEEPROM(); 
  values.mode =0;

  	// Interval in microsecs
// 	if (ITimer1.attachInterruptInterval(1000 * 1000, TimerHandler1))
// 	{
// 		Serial.print(F("Starting  ITimer1 OK, millis() = "));
// 		Serial.println(millis());
// 	}
// 	else
// 		Serial.println(F("Can't set ITimer1. Select another freq. or timer"));

// 	Serial.flush();
// }
}
