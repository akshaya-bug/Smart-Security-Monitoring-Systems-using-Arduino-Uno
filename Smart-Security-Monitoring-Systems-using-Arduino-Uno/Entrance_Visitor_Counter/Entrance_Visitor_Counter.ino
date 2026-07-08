#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins
const int IR_PIN = 2;
const int PIR_PIN = 3;
const int BUZZER_PIN = 9;

// Variables
int visitorCount = 0;
bool lastIRState = HIGH;

String motionStatus = "NO";
String securityStatus = "SAFE";

// Multiple Entry Detection
unsigned long firstEntryTime = 0;
int entryCount = 0;

void setup()
{
  pinMode(IR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop()
{
  bool irState = digitalRead(IR_PIN);
  bool pirState = digitalRead(PIR_PIN);

  //----------------------------
  // IR Visitor Detection
  //----------------------------
  if (lastIRState == HIGH && irState == LOW)
  {
    visitorCount++;

    tone(BUZZER_PIN, 1000, 150);   // Visitor Beep

    if (entryCount == 0)
      firstEntryTime = millis();

    entryCount++;
  }

  lastIRState = irState;

  //----------------------------
  // PIR Motion Detection
  //----------------------------
  if (pirState == HIGH)
  {
    motionStatus = "YES";
    securityStatus = "MOTION";
  }
  else
  {
    motionStatus = "NO";
    securityStatus = "SAFE";
  }

  //----------------------------
  // Multiple Entries Alert
  //----------------------------
  if (entryCount >= 3 && (millis() - firstEntryTime) < 10000)
  {
    securityStatus = "ALERT";

    for (int i = 0; i < 3; i++)
    {
      tone(BUZZER_PIN, 1800);
      delay(150);
      noTone(BUZZER_PIN);
      delay(100);
    }

    entryCount = 0;
  }

  if ((millis() - firstEntryTime) > 10000)
  {
    entryCount = 0;
  }

  //----------------------------
  // OLED DISPLAY
  //----------------------------

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(15,0);
  display.println("SECURITY SYSTEM");

  display.drawLine(0,10,127,10,SSD1306_WHITE);

  display.setCursor(0,18);
  display.print("Visitors : ");
  display.println(visitorCount);

  display.setCursor(0,34);
  display.print("Motion   : ");
  display.println(motionStatus);

  display.setCursor(0,50);
  display.print("Status   : ");
  display.println(securityStatus);

  display.display();

  delay(50);
}