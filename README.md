# Smart-Security-Monitoring-Systems-using-Arduino-Uno
# 🔐 Smart Security & Monitoring Systems using Arduino Uno

A collection of **6 Arduino Uno projects** developed using **IR Proximity Sensor**, **PIR Motion Sensor**, **OLED Display (SSD1306)**, **LED**, **Buzzer**, and **Push Button**. These projects demonstrate object detection, visitor counting, motion monitoring, security alert systems, and professional OLED dashboard interfaces.

---

## 📌 Project Overview

This repository contains the following projects:

1. Object / People Counter
2. Motion Activated Light
3. Motion Alert System
4. Entrance Visitor Counter
5. Smart Entrance Security System
6. Multi-Page OLED Dashboard

Each project focuses on practical sensor interfacing, real-time monitoring, and embedded system design using the Arduino Uno.

---

# 📁 Project 1 – Object / People Counter

## 🎯 Objective

Develop an object counting system using an IR Proximity Sensor that detects every object passing in front of the sensor and displays the count on an OLED display.

### Components Used

- Arduino Uno
- IR Proximity Sensor
- SSD1306 OLED Display (I2C)
- Push Button (Reset)
- Breadboard
- Jumper Wires

### Features

- Detects every object passing the IR sensor
- Displays current object count
- Displays last detection time
- Real-time OLED updates
- Reset button to clear the counter

### OLED Display

```
Object Counter

Count : 15

Status : Detected
```

### Learning Outcome

- IR Sensor Interfacing
- Digital Input Processing
- OLED Display Programming
- Counter Logic
- millis() Timer

---

# 📁 Project 2 – Motion Activated Light

## 🎯 Objective

Build an automatic lighting system using a PIR Motion Sensor that turns an LED ON whenever motion is detected.

### Components Used

- Arduino Uno
- PIR Motion Sensor
- LED
- SSD1306 OLED Display
- Breadboard
- Jumper Wires

### Features

- Detects human motion
- Turns LED ON automatically
- Displays motion status on OLED
- LED remains ON for 5 seconds after the last motion

### OLED Display

```
MOTION DETECTED
```

or

```
AREA CLEAR
```

### Learning Outcome

- PIR Motion Detection
- LED Control
- Delay-free Programming using millis()
- OLED Display

---

# 📁 Project 3 – Motion Alert System

## 🎯 Objective

Develop a security alert system that activates visual and audible alerts whenever motion is detected.

### Components Used

- Arduino Uno
- PIR Motion Sensor
- Active Buzzer
- LED
- SSD1306 OLED Display

### Features

- Motion detection
- Buzzer alarm
- Blinking LED
- OLED security alert
- Motion detection counter

### OLED Display

```
ALERT!

Motion Detected
```

### Learning Outcome

- Security System Design
- Alarm Logic
- Motion Monitoring
- Event Counting
- Multi-output Control

---

# 📁 Project 4 – Entrance Visitor Counter

## 🎯 Objective

Create an entrance monitoring system using both IR and PIR sensors to count visitors and confirm movement.

### Components Used

- Arduino Uno
- IR Proximity Sensor
- PIR Motion Sensor
- SSD1306 OLED Display

### Features

- Visitor counting
- Motion confirmation
- Live OLED dashboard
- Highest visitor count during runtime

### OLED Display

```
Visitor Counter

Visitors : 24

Motion : YES
```

### Learning Outcome

- Multi-sensor Integration
- Visitor Counting
- Motion Verification
- Real-time Dashboard Design

---

# 📁 Project 5 – Smart Entrance Security System

## 🎯 Objective

Develop a complete entrance security system by combining IR and PIR sensors with intelligent alert mechanisms.

### Components Used

- Arduino Uno
- IR Proximity Sensor
- PIR Motion Sensor
- SSD1306 OLED Display
- Active Buzzer

### Features

- Entry detection
- Motion confirmation
- Security status monitoring
- Visitor counting
- Intruder detection
- Multiple-entry alert
- Different buzzer patterns

### OLED Display

```
Visitors : 12

Motion : YES

Status : ACTIVE
```

### Learning Outcome

- Embedded Security Systems
- Multi-Sensor Fusion
- Alarm Generation
- Event Detection
- Smart Monitoring

---

# 📁 Project 6 – Multi-Page OLED Dashboard

## 🎯 Objective

Design a professional OLED monitoring interface capable of displaying multiple dashboards using a push button.

### Components Used

- Arduino Uno
- IR Proximity Sensor
- PIR Motion Sensor
- SSD1306 OLED Display
- Push Button

### Features

### Page 1

```
IR Dashboard

IR Counter

Count : 12
```

### Page 2

```
PIR Dashboard

Motion : YES
```

### Page 3

```
Security Dashboard

Visitors : 12

Motion : YES

Status : ACTIVE
```

### Additional Features

- Manual page switching
- Automatic page switching every 5 seconds
- Professional OLED interface
- Live sensor monitoring

### Learning Outcome

- OLED User Interface Design
- Menu Navigation
- Push Button Handling
- Multi-Page Display System
- Real-Time Sensor Monitoring

---

# 🛠 Hardware Used

- Arduino Uno
- IR Proximity Sensor
- PIR Motion Sensor
- SSD1306 OLED Display (128×64, I2C)
- Active Buzzer
- LED
- Push Button
- Breadboard
- Jumper Wires
- USB Cable

---

# 💻 Software Used

- Arduino IDE
- C/C++
- Adafruit GFX Library
- Adafruit SSD1306 Library

---

# 📚 Concepts Covered

- Arduino Programming
- Digital Input & Output
- Sensor Interfacing
- IR Object Detection
- PIR Motion Detection
- OLED Display Programming
- Event Counting
- Embedded Security Systems
- Real-Time Monitoring
- Push Button Interface
- Multi-Page OLED Dashboard
- Non-blocking Programming using `millis()`

---

# 🚀 Repository Structure


Smart-Security-Monitoring-Systems/
│
├── Project-1_Object_Counter/
IMAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/b17500a8-ffdd-4141-b1f6-0ace4c4e98e4" />
IMAGE 2:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/ca5f90c8-251b-411c-ae83-7874d392e7ca" />

├── Project-2_Motion_Activated_Light/
IMAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/08af35d9-6120-4465-ae4d-94f22bcbbec5" />

├── Project-3_Motion_Alert_System/
IMAGE1 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/6ec33b92-cb41-4730-b003-68bb72b644c3" />

├── Project-4_Entrance_Visitor_Counter/
IMAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/b08c30c2-6472-43e7-a27c-67fe5d984fcc" />
IMAGE 2:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/83772a4a-1d5d-4b79-861a-62c236881236" />

├── Project-5_Smart_Entrance_Security/
IMAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/ad6fc58d-27f6-4954-925a-bd2a869415fa" />
IMAGE 2:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/b03218db-0319-442f-ae5f-2e64cdceb9e2" />

├── Project-6_Multi_Page_OLED_Dashboard/
PAGE 1:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/e2036a85-deb5-405a-986d-aedb6fa1a9c3" />
PAGE 2:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/72e39c80-f8e4-437f-8493-35e51e05de62" />
PAGE 3:
<img width="1600" height="1200" alt="image" src="https://github.com/user-attachments/assets/13ccf0e3-06ee-46bc-a20e-3dacf9e5ab21" />


# 🎯 Learning Outcomes

By completing these projects, you will gain hands-on experience in:

- Sensor interfacing using Arduino Uno
- Embedded system programming
- Real-time object and motion detection
- OLED display development
- Security and monitoring system design
- User interface implementation
- Event-based programming
- Practical IoT and automation concepts

---

## ⭐ If you found this repository useful, consider giving it a Star!
