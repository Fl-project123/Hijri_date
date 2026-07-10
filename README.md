# Hijri_date
An Arduino library for converting Gregorian (Masehi) dates to Hijri (Islamic) dates with multi-language support.

## Overview
This library uses the **Tabular Islamic Calendar** algorithm based on the **Julian Day Number (JDN)** to provide lightweight and efficient Hijri date conversions. It is highly optimized for microcontrollers, making it ideal for IoT projects such as digital prayer clocks (Jam Digital Masjid) on Arduino, ESP8266, and ESP32.

## Features
- Convert Gregorian date to Hijri date accurately.
- **Multi-language Support:** Choose between English (Default) and Indonesian transliterations.
- Manual offset (correction) support to adjust lunar calendar visibility.
- Optimized memory allocation to prevent RAM fragmentation on 8-bit AVR boards (Uno/Nano).

## Installation
1. Download this repository as a `.zip` file.
2. In the Arduino IDE, go to **Sketch** -> **Include Library** -> **Add .ZIP Library**.
3. (Or) Search for `Hijri_date` in the **Library Manager** once the index is updated.

## Usage Example

```cpp
#include <Hijri_date.h>

// Instantiate the class matching the library name
Hijri_date hd;

void setup() {
  Serial.begin(115200);
  while(!Serial); // Wait for serial monitor to connect
  
  Serial.println("--- Hijri_date Library v1.0.1 ---");
  
  // Example Input: July 9, 2026 with 0 day offset
  int day = 9;
  int month = 7;
  int year = 2026;
  int offset = 0;

  // 1. Default Version (English)
  hd.update(day, month, year, offset); 
  Serial.print("Default (EN): ");
  Serial.println(hd.getFullDate()); // Output: 24 Muharram 1448 H

  // 2. Switching Language to Indonesian
  hd.setLanguage(LANG_ID);
  hd.update(day, month, year, offset); 
  Serial.print("Local (ID)  : ");
  Serial.println(hd.getFullDate()); // Output: 24 Muharram 1448 H
}

void loop() {
  // Put your main code here, to run repeatedly:
}
```
### API Reference
-void setLanguage(uint8_t lang) : Sets the global language output. Use LANG_EN for English or LANG_ID for Indonesian.
-void update(int d, int m, int y, int k = 0) : Processes the conversion. k is the optional manual day offset (e.g., -1, 0, 1).
-int hDay() : Returns the Hijri day (1-30).
-int hMonth() : Returns the Hijri month (1-12).
-int hYear() : Returns the Hijri year.
-String getMonthName() : Returns the string name of the current Hijri month based on the selected language.
-String getFullDate() : Returns the complete formatted date string (e.g., "24 Muharram 1448 H").

### License
This project is licensed under the MIT License.
