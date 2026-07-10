#include <Hijri_date.h>

Hijri_date hd;

void setup() {
  Serial.begin(115200);
  while(!Serial); 
  
  Serial.println("--- Karya Fa'al - Hijri_date ---");

  // Input tanggal Masehi yang sama: 9 Juli 2026
  
  // 1. Uji Coba Versi Default (Bahasa Inggris)
  hd.update(9, 7, 2026, 0); 
  Serial.print("Default (EN) : ");
  Serial.println(hd.getFullDate()); // Output: 24 Muharram 1448 H

  // 2. Uji Coba Ubah Bahasa ke Indonesia
  hd.setLanguage(LANG_ID);
  hd.update(9, 7, 2026, 0); 
  Serial.print("Ubah ke (ID) : ");
  Serial.println(hd.getFullDate()); // Output: 24 Muharram 1448 H (Menggunakan ejaan lokal jika berbeda)
}

void loop() {}
