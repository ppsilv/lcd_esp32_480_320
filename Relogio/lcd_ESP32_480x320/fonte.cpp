#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>
#include <Fonts/FreeMono18pt7b.h>
#include <Fonts/FreeMono24pt7b.h>

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include <FreeDefaultFonts.h>
#include "colors.h"


void setupFonte(void)
{

    uint16_t ID = tft.readID();
    Serial.println("Example: Font_simple");
    Serial.print("found ID = 0x");
    Serial.println(ID, HEX);
    if (ID == 0xD3D3) ID = 0x9481; //force ID if write-only display
    tft.begin(ID);
    tft.setRotation(1);
    tft.setFont(&FreeSerif12pt7b);
}

void fontePrint(std::string str)
{
  tft.print(str.c_str());
}

void setTextColor(int cor, int fundo)
{
  tft.setTextColor(cor, fundo);
}

void setCursor(int col, int row)
{
  tft.setCursor(col, row);
}

void setTextSize(int size)
{
    tft.setTextSize(size);
}

void clear(int fundo)
{
    tft.fillScreen(fundo);  
}

void loopFonte()
{
    tft.fillScreen(WHITE);
    //showmsgXY(5, 100, 2, &FreeMono18pt7b, "01/02/2025");

    tft.setTextColor(VERMELHO, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 0);
    tft.print("VERMELHO");

    tft.setTextColor(AMARELO, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 20);
    tft.print("AMARELO");

    tft.setTextColor(VERDECLARO, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 40);
    tft.print("VERDE CLARO");

    tft.setTextColor(VERDE, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 60);
    tft.print("VERDE");

    tft.setTextColor(CIANO, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 80);
    tft.print("CIANO");

    tft.setTextColor(AZUL, WHITE);
    tft.setTextSize(3);
    tft.setCursor(0, 100);
    tft.print("AZUL");


    delay(10000);
}

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg);

void loop1(void)
{
    tft.fillScreen(BLACK);
    showmsgXY(20, 10, 1, NULL, "System x1");
    showmsgXY(20, 24, 2, NULL, "System x2");
    showmsgXY(20, 60, 1, &FreeSans9pt7b, "FreeSans9pt7b");
    showmsgXY(20, 80, 1, &FreeSans12pt7b, "FreeSans12pt7b");
    showmsgXY(20, 100, 1, &FreeSerif12pt7b, "FreeSerif12pt7b");
    showmsgXY(20, 120, 1, &FreeSmallFont, "FreeSmallFont");
    showmsgXY(5, 180, 1, &FreeSevenSegNumFont, "01234");
    showmsgXY(5, 190, 1, NULL, "System Font is drawn from topline");
    tft.setTextColor(RED, GREY);
    tft.setTextSize(2);
    tft.setCursor(0, 220);
    tft.print("7x5 can overwrite");
    delay(1000);
    tft.setCursor(0, 220);
    tft.print("if background set");
    delay(1000);
    showmsgXY(5, 260, 1, &FreeSans9pt7b, "Free Fonts from baseline");
    showmsgXY(5, 285, 1, &FreeSans9pt7b, "Free Fonts transparent");
    delay(1000);
    showmsgXY(5, 285, 1, &FreeSans9pt7b, "Free Fonts XXX");
    delay(1000);
    showmsgXY(5, 310, 1, &FreeSans9pt7b, "erase backgnd with fillRect()");
    delay(10000);
}

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
    int16_t x1, y1;
    uint16_t wid, ht;
    tft.drawFastHLine(0, y, tft.width(), WHITE);
    tft.setFont(f);
    tft.setCursor(x, y);
    tft.setTextColor(GREEN);
    tft.setTextSize(sz);
    tft.print(msg);
    delay(1000);
}
