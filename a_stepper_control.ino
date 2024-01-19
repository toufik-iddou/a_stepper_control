#if !defined( ESP32 )
	#error This code is intended to run on the ESP32 platform!.
#endif
// #include <Arduino.h>
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
#include <PID_v1.h>  // Include the PID library


// Define constants

#define STEP_PIN  18
#define DIR_PIN   19
#define ENABLE_PIN 21
#define pi 3.1416
#define DEG2RAD 0.0175
#define ch1 4
#define ch2 2
#define Stepdevider 1
// #define PIN_D3 13
#define TIMER1_INTERVAL_MS        2000
#define STEP_TIME 520

#define MEMORY_SIZE (4*sizeof(float)+sizeof(char))

#define PI 3.1416

#define ADDRESS_MODE 0
#define ADDRESS_V (ADDRESS_MODE + sizeof(char) )
#define ADDRESS_R (ADDRESS_V + sizeof(float))
#define ADDRESS_TSR (ADDRESS_R + sizeof(float))
#define ADDRESS_THETA (ADDRESS_TSR + sizeof(float))
