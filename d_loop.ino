void loop(void) {
    long unsigned int currentMillis = millis() ;
    float alpha = angle(currentMillis);
    int pos = angleToPosition(alpha);
    
    setpoint = pos ;  
    // Read sensor input
    sensorInput = counter / 2;
    // Compute PID output
    myPID.Compute();
    // Move the stepper motor usinsg the PID output
    moveStepper(output);
    Serial.println(alpha);
  server.handleClient();
  
}
