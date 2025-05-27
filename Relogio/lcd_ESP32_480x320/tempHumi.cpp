/*
*	AM2302-Sensor_Example.ino
*
*	Author: Frank Häfele
*	Date:	21.11.2023
*
*	Object: Measure Sensor Data of AM2302-Sensor with Arduino IDE
*/

#include <AM2302-Sensor.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "colors.h"

#define tempCol 5
#define tempRow 290
#define humiCol 240
#define humiRow 290

constexpr unsigned int SENSOR_PIN {21U};

AM2302::AM2302_Sensor am2302{SENSOR_PIN};

extern std::string format_number(int );

//int temp = 25;
//int humi = 10;

std::string sTemp_old="";
std::string sHumi_old="";

void setupTempHumi() {

   Serial.print(F("\n >>> AM2302-Temp and humidity Sensors <<<\n\n"));

   // set pin and check for sensor
   if (am2302.begin()) {
    Serial.println("AM2302 started...");
      // this delay is needed to receive valid data,
      // when the loop directly read again
      delay(3000);
   }
   else {
    Serial.println("AM2302 error...");
      while (true) {
      Serial.println("Error: sensor check. => Please check sensor connection!");
      delay(10000);
      }
   }
}
extern void fontePrint(std::string str);
extern void setTextColor(int cor, int fundo);
extern void setCursor(int col, int row);
extern void setTextSize(int size);

void loopTempHumi() {
  
 auto status = am2302.read();
 Serial.print("\n\nstatus of sensor read(): ");
 Serial.println(status);
  
  std::string temp =  format_number(am2302.get_Temperature());
  std::string humi =  format_number(am2302.get_Humidity());

  std::string sTemp= "Temp: " + format_number(std::stoi(temp)) ;
  std::string sHumi= " Humi: " + format_number(std::stoi(humi)) + "%";

  if (  std::stoi( temp ) >= 27 ){
    setTextColor(VERMELHO, WHITE);
    setTextSize(2);
    setTextColor(BLACK, WHITE);
    setCursor(tempCol, tempRow);
    fontePrint(sTemp_old.c_str());
    setTextColor(VERMELHO, WHITE);
    setCursor(tempCol, tempRow);
    fontePrint(sTemp.c_str());

    setTextSize(1);
    setCursor(200, tempRow-22);
    fontePrint("o");
  }else{
    setTextSize(2);
    setTextColor(BLACK, WHITE);
    setCursor(tempCol, tempRow);
    fontePrint(sTemp_old.c_str());
    setTextColor(GREEN, WHITE);
    setCursor(tempCol, tempRow);
    fontePrint(sTemp.c_str());

    setTextSize(1);
    setCursor(200, tempRow-22);
    fontePrint("o");
  }
  if (  std::stoi( humi ) > 60 || std::stoi( humi ) < 50  ){
    setTextColor(VERMELHO, WHITE);
    setTextSize(2);
    setTextColor(BLACK, WHITE);
    setCursor(humiCol, humiRow);
    fontePrint(sHumi_old.c_str());
    setTextColor(VERMELHO, WHITE);
    setCursor(humiCol, humiRow);
    fontePrint(sHumi.c_str());
  }else{
    setTextColor(GREEN, WHITE);
    setTextSize(2);
    setTextColor(BLACK, WHITE);
    setCursor(humiCol, humiRow);
    fontePrint(sHumi_old.c_str());
    setTextColor(GREEN, WHITE);
    setCursor(humiCol, humiRow);
    fontePrint(sHumi.c_str());
  }

  sTemp_old = sTemp;
  sHumi_old = sHumi;
}