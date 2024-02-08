void loop(void) {

    int pos = angleToPosition(values.a);
    
    setpoint = pos ;  
    // Read sensor input
    sensorInput = (int)(counter/2);
    // Compute PID output
    myPID.Compute();
    // Move the stepper motor usinsg the PID output

 
    moveStepper(output);
  digitalWrite(ENABLE_PIN, HIGH);
 
   server.handleClient();
}
