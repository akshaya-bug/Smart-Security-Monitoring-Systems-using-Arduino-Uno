#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int pirPin = 2;
const int ledPin = 8;

// Variables
bool motionDetected = false;
unsigned long lastMotionTime = 0;
const unsigned long lightDelay = 5000;   // Keep LED ON for 5 seconds

void setup() {

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int motion = digitalRead(pirPin);

  // Motion detected
  if (motion == HIGH) {

    motionDetected = true;
    lastMotionTime = millis();

    digitalWrite(ledPin, HIGH);
  }

  // Turn OFF LED after 5 seconds of no motion
  if (motionDetected && (millis() - lastMotionTime >= lightDelay)) {

    motionDetected = false;
    digitalWrite(ledPin, LOW);
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(8,0);
  display.println("Automatic Lighting");

  display.drawLine(0,10,128,10,SSD1306_WHITE);

  display.setTextSize(2);

  if (motionDetected) {

    display.setCursor(5,22);
    display.println("MOTION");

    display.setCursor(8,46);
    display.println("DETECTED");

  } else {

    display.setCursor(15,32);
    display.println("AREA");

    display.setCursor(15,52);
    display.println("CLEAR");
  }

  display.display();

  delay(100);
}