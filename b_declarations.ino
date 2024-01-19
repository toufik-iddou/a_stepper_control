//types
typedef struct {
  char mode;
  float V;
  float R;
  float TSR;
  float theta;
 }MyValues;

//Model variables
MyValues values;
//system variables
float W;
bool FixedMode = false;
const char *ssid = "hemiche";
const char *password = "12345678";
WebServer server(80);
const int led = 13;
int counter=0;
ESP32Timer ITimer1(1);
//functions
//root functions
void handleRoot();
void handleNotFound(); 
void handleNotFound2(); 
String navigateTo(String path);
String homePage();
void handleGetHome();
void handlePostHome();
//memory functions
void writeDataToEEPROM(float V,float R,float TSR,float theta);
MyValues readDataFromEEPROM();
//timers functions
void IRAM_ATTR onChangePosition();
bool IRAM_ATTR movementInterruption(void * timerNo);
// bool IRAM_ATTR TimerHandler1(void * timerNo)
//model functions
float angle(float theta,float TSR);
int angleToPosition(float angle);
bool moveToPosition(int pos);
void dispatch();
//stepper
// Create a stepper motor object
AccelStepper stepper(1, STEP_PIN, DIR_PIN);

// PID constants (adjust as needed)
double kp = 1.0;  // Proportional gain
double ki = 0.0;  // Integral gain
double kd = 0.01;  // Derivative gain

// Variables for PID control
double sensorInput = 0.0;
double setpoint = 0.0;
double output = 0.0;

// Create PID objects
PID myPID(&sensorInput, &output, &setpoint, kp, ki, kd, DIRECT);
