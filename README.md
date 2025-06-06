# RFID-using-arduino
Arduino-based RFID access control system with LCD display and UID authentication.
# RFID Access Control System using Arduino

This project is a simple RFID-based access control system built using an **Arduino Uno**, **MFRC522 RFID reader**, and a **16x2 I2C LCD display**. The system reads an RFID tag, displays its UID, and checks whether access should be granted or denied based on a predefined UID.

## 🚀 Features

- Reads RFID card UID via MFRC522
- Displays UID and access status on an I2C LCD
- Grants or denies access using a basic conditional check
- Controls output pins to simulate door opening or alarm

## 🛠️ Hardware Components

- Arduino Uno (or compatible board)
- MFRC522 RFID Reader
- 16x2 I2C LCD Display
- RFID Tag/Card
- Red and Green LEDs (or output devices)
- Breadboard and jumper wires

## 🔌 Connections

### MFRC522 RFID Reader
| MFRC522 Pin | Arduino Pin |
|-------------|-------------|
| SDA         | 10          |
| SCK         | 13          |
| MOSI        | 11          |
| MISO        | 12          |
| RST         | 9           |
| VCC         | 3.3V        |
| GND         | GND         |

### LCD Display (I2C)
| LCD Pin | Arduino Pin |
|---------|-------------|
| SDA     | A4          |
| SCL     | A5          |
| VCC     | 5V          |
| GND     | GND         |

### LEDs
- Green LED (Access Granted) → Pin 4  
- Red LED (Access Denied) → Pin 2  

## 📋 How It Works

1. The system waits for an RFID card to be scanned.
2. It reads the UID of the card and displays it on the LCD.
3. If the UID matches the authorized UID (`5dfcbb2`), it shows **"Access Provided"** and turns on the green LED.
4. If the UID doesn't match, it shows **"Access Denied"** and turns on the red LED.



## 📦 Libraries Used

- `MFRC522` – for RFID functionality  
- `LiquidCrystal_I2C` – to control the LCD over I2C  
- `SPI` and `Wire` – for communication protocols



