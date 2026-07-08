#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin Definitions
const int IR_PIN = 2;
const int PIR_PIN = 3;

// Variables
int visitorCount = 0;
int highestCount = 0;

bool lastIRState = HIGH;

void setup()
{
  pinMode(IR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("OLED Failed");
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop()
{
  bool irState = digitalRead(IR_PIN);
  bool motion = digitalRead(PIR_PIN);

  // Count visitor once
  if (lastIRState == HIGH && irState == LOW)
  {
    visitorCount++;

    if (visitorCount > highestCount)
      highestCount = visitorCount;

    Serial.print("Visitors : ");
    Serial.println(visitorCount);
  }

  lastIRState = irState;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(12,0);
  display.println("Visitor Counter");

  display.drawLine(0,10,127,10,SSD1306_WHITE);

  display.setCursor(0,18);
  display.print("Visitors: ");
  display.println(visitorCount);

  display.setCursor(0,34);
  display.print("Motion : ");

  if(motion)
    display.println("YES");
  else
    display.println("NO");

  display.setCursor(0,50);
  display.print("Highest: ");
  display.print(highestCount);

  display.display();

  delay(50);
}