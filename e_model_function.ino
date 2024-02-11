void IRAM_ATTR onChangePosition() {
  if(digitalRead(ch1) == digitalRead(ch2) ){
    counter++;
    }else{
      counter--;
      }
     counter%=400;
}
float angle(float t){
  float alpha = values.a*sin(t*2*PI*values.f+values.ph*DEG2RAD);
  
  return alpha ;
  }
  
 int angleToPosition(float angle){
  return (int)(angle/1.8)%200;
  }
void dispatch(){
  myPID.SetTunings(pidC.p, pidC.i, pidC.d);
}

void moveStepper(double output) {

  digitalWrite(ENABLE_PIN, LOW);
  // Move the stepper motor based on the PID output
  stepper.move(output);
  // Enable the motor and run to the target position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  // Disable the motor when not in use
  stepper.disableOutputs();
      
}

