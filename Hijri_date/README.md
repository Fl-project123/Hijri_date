# Hijri_date
An Arduino library for converting Gregorian (Masehi) dates to Hijri (Islamic) dates.

## Overview
This library uses the **Tabular Islamic Calendar** algorithm based on the **Julian Day Number (JDN)** to provide accurate Hijri date conversions. It is lightweight and compatible with Arduino, ESP8266, and ESP32.

## Features
- Convert Gregorian date to Hijri date.
- Manual offset (correction) support.
- Get Hijri month names in English/Arabic transliteration.
- Get full formatted date string.

## Installation
1. Download this repository as a `.zip` file.
2. In Arduino IDE, go to **Sketch** -> **Include Library** -> **Add .ZIP Library**.
3. (Or) Search for `Hijri_date` in the **Library Manager** (once registered).

## Usage Example
```cpp
#include <Hijri_date.h>

Hijri_date hd;

void setup() {
  Serial.begin(115200);
  
  // Update with: Day, Month, Year, and Manual Offset
  hd.update(5, 4, 2026, 0); 
  
  Serial.println(hd.getFullDate()); // Example Output: 17 Shawwal 1447 H
}

void loop() {}