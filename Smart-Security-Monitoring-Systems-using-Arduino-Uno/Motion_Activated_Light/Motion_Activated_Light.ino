#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin Definitions
const int PIR_PIN = 2;
const int LED_PIN = 8;
const int BUZZER_PIN = 9;

// Variables
bool lastMotionState = LOW;
int motionCount = 0;

unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (1);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  bool motion = digitalRead(PIR_PIN);

  // Count only new detections
  if (motion == HIGH && lastMotionState == LOW) {
    motionCount++;
  }

  lastMotionState = motion;

  //==============================
  // MOTION DETECTED
  //==============================
  if (motion == HIGH) {

    digitalWrite(BUZZER_PIN, HIGH);

    // Blink LED every 300ms
    if (millis() - previousMillis >= 300) {
      previousMillis = millis();
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(22,0);
    display.println("ALERT!");

    display.setTextSize(1);

    display.setCursor(10,25);
    display.println("Motion Detected");

    display.setCursor(0,45);
    display.print("Count : ");
    display.println(motionCount);

    display.display();
  }

  //==============================
  // NO MOTION
  //==============================
  else {

    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(18,0);
    display.println("Security System");

    display.drawLine(0,10,127,10,SSD1306_WHITE);

    display.setCursor(18,25);
    display.println("Monitoring...");

    display.setCursor(0,50);
    display.print("Count : ");
    display.print(motionCount);

    display.display();
  }

  delay(50);
}