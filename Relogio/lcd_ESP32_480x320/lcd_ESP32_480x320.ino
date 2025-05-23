
extern void setupClock();
extern void loopClock();
extern void setupFonte(void);
extern void loopFonte(void);
extern void setupDemo();
extern void loopDemo();
//extern void setFont(const GFXfont * f );
extern void setFont( );

extern void clearScreen();
extern void frame();

void setup()
{
  Serial.begin(115200);
  setupDemo();
  setupClock();
  setupFonte();
  setFont();
  clearScreen();
  frame();
}

void loop()
{
  loopClock();
}