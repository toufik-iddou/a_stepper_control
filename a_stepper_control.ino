#if !defined( ESP32 )
	#error This code is intended to run on the ESP32 platform!.
#endif

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <EEPROM.h>
#include<math.h>
#include <ArduinoJson.h>
#include <CustomJWT.h>
#include "ESP32TimerInterrupt.h"
#include <AccelStepper.h>
#include <PID_v1.h> 


// Define constants

#define STEP_PIN  18
#define DIR_PIN   19
#define ENABLE_PIN 21
#define DEG2RAD 0.0175
#define ch1 4
#define ch2 2
#define POWER_PIN 0
#define Stepdevider 1
// #define PIN_D3 13
#define TIMER1_INTERVAL_MS 2000
#define STEP_TIME 520

#define MEMORY_SIZE (6*sizeof(float))

#define PI 3.1416

#define ADDRESS_A 0
#define ADDRESS_F (ADDRESS_A + sizeof(float))
#define ADDRESS_PH (ADDRESS_F + sizeof(float))
#define ADDRESS_P (ADDRESS_PH + sizeof(float))
#define ADDRESS_I (ADDRESS_P + sizeof(float))
#define ADDRESS_D (ADDRESS_I + sizeof(float))
