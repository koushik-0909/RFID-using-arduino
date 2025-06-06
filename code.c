#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define pins for MFRC522 module
#define SS_PIN 10
#define RST_PIN 9
String uidString = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// Initialize the LCD, set the I2C address (0x27 is the default)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Scan the RFID!");

  // Initialize SPI bus
  SPI.begin();
  mfrc522.PCD_Init();  // Initialize MFRC522 RFID reader
}

void loop() {
  // Clear the previous UID string each time a new scan starts
  uidString = "";

  // Look for new RFID cards
  if (mfrc522.PICC_IsNewCardPresent()) {
    // Select one of the cards
    if (mfrc522.PICC_ReadCardSerial()) {
      // Print the UID to the Serial Monitor
      Serial.print("UID of the card: ");
     
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        uidString += String(mfrc522.uid.uidByte[i], HEX);
       
      }
      Serial.println(uidString);

      // Display UID on the LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Card UID: ");
      lcd.setCursor(0, 1);
      lcd.print(uidString);
      uidString.toLowerCase(); 

      // Check for access based on UID
      if (uidString == "5dfcbb2") {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Provided");
        digitalWrite(4,HIGH);
        delay(3000);
        digitalWrite(4,LOW);
        lcd.setCursor(0,1);
        lcd.print("Door opens!");
        delay(2000);
        lcd.clear();
        lcd.print("Scan the RFID!");

      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        digitalWrite(2,HIGH);
        delay(2000);
        digitalWrite(2,LOW);
        lcd.setCursor(0,1);
        lcd.print("Door not opened!");
        delay(1000);
        lcd.clear();
        lcd.print("Scan the RFID!");
      }

      delay(2000);  // Wait for 2 seconds to show the UID and result

      mfrc522.PICC_HaltA();
    }
    
  }
}
