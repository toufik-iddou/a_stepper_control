void loop(void) {
  if (values.mode == 2) {
    long unsigned int currentMillis = millis() ;
    float T = 2 * PI / W;
    //currentMillis -= floor((currentMillis) / (T)) * (T);
    float alpha = angle(W * currentMillis / 1000, values.TSR);
    int pos = angleToPosition(alpha);
    //moveToPosition(pos);
    setpoint = pos ;  // Convert position to steps (assuming 16 microsteps per step)

    // Read sensor input
    sensorInput = counter / 2;

    // Compute PID output
    myPID.Compute();

    // Move the stepper motor using the PID output
    moveStepper(output);
    Serial.println(counter / 2);

  }
  server.handleClient();
}
