bool IRAM_ATTR movementInterruption(void * timerNo)
{

	return true;
}


void IRAM_ATTR onChangePosition() {
  if(digitalRead(ch1) == digitalRead(ch2) ){
    counter++;
    }else{
      counter--;
      }
     counter%=400;
}
float angle(float theta,float TSR){
  float alpha = atan(sin(theta)/(cos(theta)+TSR))/DEG2RAD;
  return alpha ;
  }
  
 int angleToPosition(float angle){
  return (int)(angle/1.8) %200;
  }

bool moveToPosition(int pos){
 
 int steps = pos-counter/2;
  if(steps==0){
   return false;
   }
  if(steps>0){
    digitalWrite(DIR_PIN,HIGH);
    }
  else{ 
    digitalWrite(DIR_PIN,LOW);
    steps*=(-1);
    }
  for(int i =0;i<steps;i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_TIME);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_TIME);
    }
     Serial.print("counter");
  Serial.println(counter);
    return true;
  }
void dispatch(){
  W = values.TSR*values.V/values.R;
}

void moveStepper(double output) {
  // Move the stepper motor based on the PID output
  stepper.move(output);

  // Enable the motor and run to the target position
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }

  // Disable the motor when not in use
  stepper.disableOutputs();
}
