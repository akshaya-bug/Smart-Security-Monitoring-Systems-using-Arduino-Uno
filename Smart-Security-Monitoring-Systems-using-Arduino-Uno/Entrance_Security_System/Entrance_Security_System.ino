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
const int BUTTON_PIN = 4;

// Variables
int visitorCount = 0;
bool lastIRState = HIGH;

int currentPage = 0;

bool lastButtonState = HIGH;

unsigned long lastPageChange = 0;
const unsigned long autoSwitchTime = 5000;

void setup()
{
  pinMode(IR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

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
  // -----------------------------
  // IR Counter
  // -----------------------------
  bool irState = digitalRead(IR_PIN);

  if (lastIRState == HIGH && irState == LOW)
  {
    visitorCount++;
  }

  lastIRState = irState;

  // -----------------------------
  // Push Button Page Change
  // -----------------------------
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW)
  {
    currentPage++;

    if (currentPage > 2)
      currentPage = 0;

    lastPageChange = millis();

    delay(200);
  }

  lastButtonState = buttonState;

  // -----------------------------
  // Auto Page Change Every 5 sec
  // -----------------------------
  if (millis() - lastPageChange >= autoSwitchTime)
  {
    currentPage++;

    if (currentPage > 2)
      currentPage = 0;

    lastPageChange = millis();
  }

  // -----------------------------
  // OLED Display
  // -----------------------------
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  switch(currentPage)
  {

    //============================
    // PAGE 1
    //============================
    case 0:

      display.setTextSize(1);

      display.setCursor(15,0);
      display.println("IR Dashboard");

      display.drawLine(0,10,127,10,WHITE);

      display.setCursor(20,20);
      display.println("IR Counter");

      display.setTextSize(2);
      display.setCursor(18,42);
      display.print("Count:");
      display.print(visitorCount);

      break;

    //============================
    // PAGE 2
    //============================
    case 1:

      display.setTextSize(1);

      display.setCursor(15,0);
      display.println("PIR Dashboard");

      display.drawLine(0,10,127,10,WHITE);

      display.setCursor(18,20);
      display.println("PIR Monitor");

      display.setTextSize(2);

      display.setCursor(0,42);
      display.print("Motion:");

      if (digitalRead(PIR_PIN))
        display.print("YES");
      else
        display.print("NO");

      break;

    //============================
    // PAGE 3
    //============================
    case 2:

      display.setTextSize(1);

      display.setCursor(5,0);
      display.println("Security Dashboard");

      display.drawLine(0,10,127,10,WHITE);

      display.setCursor(0,18);
      display.print("Visitors:");
      display.println(visitorCount);

      display.setCursor(0,34);
      display.print("Motion :");

      if (digitalRead(PIR_PIN))
        display.println("YES");
      else
        display.println("NO");

      display.setCursor(0,50);
      display.print("Status :");

      if (digitalRead(PIR_PIN))
        display.println("ACTIVE");
      else
        display.println("SAFE");

      break;
  }

  display.display();

  delay(50);
}