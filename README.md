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
