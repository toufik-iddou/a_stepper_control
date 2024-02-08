//types
typedef struct {
  float a;
  float f;
  float ph;
}MyValues;

typedef struct {
  float p;
  float i;
  float d;
}PIDParams;

//Model variables
MyValues values;
PIDParams pidC;
//system variables
const char *ssid = "motor controler";
const char *password = "12345678";
WebServer server(80); //init server using http protocol
int counter=0;
ESP32Timer ITimer1(1);
//functions
//setups
void setupPins();
void setupInterrupt();
void setupRoutes();
void setupStepper();
void setupPID();
void setupWifi();
void setupMDNS();
//root functions
void handleRoot();
void handleNotFound(); 
void handleNotFound2(); 

String navigateTo(String path);
String homePage();
String controlePage();
void handleGetController();
void handleSetController();
void handleSetParams();
//memory functions
void writeDataToParamsEEPROM(float a,float f, float ph);
void writeDataToContorleEEPROM( float p, float i, float d);
void readDataFromEEPROM();
//timers functions
void IRAM_ATTR onChangePosition();
// bool IRAM_ATTR TimerHandler1(void * timerNo)
//model functions
float angle(float t);
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
//request 
bool response = false;
