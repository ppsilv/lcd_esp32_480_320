#include <time.h>
#include <WiFi.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

const char* ssid     = "OSAP1_2G";
const char* password = "santos@info09";
//const char* ssid     = "OpenSoftware4";
//const char* password = "santos@info09";


long timezone = -3;
byte daysavetime = 0;
struct tm tmstruct ;

std::string sdata = "";
std::string shora = "";
std::string lastDate = "";
std::string lastTime = "";

extern void fontePrint(std::string str);
extern void setTextColor(int cor, int fundo);
extern void setCursor(int col, int row);
extern void setTextSize(int size);
extern void clear(int fundo);

#define WHITE       0xFFFF
#define BLACK       0x0000
#define VERMELHO    0xF800
#define AMARELO     0xFF00
#define VERDECLARO  0x07E0
#define VERDE       0x07C0
#define CIANO       0x07F0
#define AZUL        0x003F
#define CINZA       0x8410

std::string format_number(int number) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}

void getDateTime()
{
  getLocalTime(&tmstruct);

  int imes = tmstruct.tm_mon + 1;

  String ano = String((tmstruct.tm_year) + 1900) ;
  std::string mes = format_number(imes );
  std::string dia = format_number(tmstruct.tm_mday);
  
  std::string hora =  format_number(tmstruct.tm_hour);
  std::string min  =  format_number(tmstruct.tm_min);
  std::string seg  =  format_number(tmstruct.tm_sec);

  sdata = dia +"/"+ mes +"/" + ano.c_str();
  shora = hora +":"+ min  +":"+ seg; // hour.c_str();

}

void printDateTime()
 {
  Serial.println(sdata.c_str());
  Serial.println(shora.c_str());

  setTextColor(VERMELHO, WHITE);
  setTextSize(2);
  setCursor(250, 50);
  fontePrint(sdata.c_str());

  setTextColor(BLACK, WHITE);
  setTextSize(5);
  setCursor(10, 200);
  fontePrint(lastTime.c_str());

  setTextColor(AZUL, WHITE);
  setTextSize(5);
  setCursor(10, 200);
  fontePrint(shora.c_str());
  lastTime = shora;
  lastDate = sdata;

}

void setupClock() {
  Serial.begin(115200);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int i = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Contacting Time Server");
  configTime(3600 * timezone, daysavetime * 3600, "time.nist.gov", "0.pool.ntp.org", "1.pool.ntp.org");
  clear(WHITE);

  tmstruct.tm_year = 0;
  getDateTime();
  lastTime = shora;
  lastDate= sdata;
  printDateTime();
}



void loopClock() 
{
  getDateTime();
  printDateTime();

  delay(1000);
}