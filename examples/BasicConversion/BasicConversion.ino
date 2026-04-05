#include <Hijri_date.h>

HijriDate hd;

void setup() {
  Serial.begin(115200);
  
  // Update: Tanggal 20, Bulan 3, Tahun 2026, Koreksi 0
  hd.update(20, 3, 2026, 0); 

  Serial.println("Karya Fa'al - Hijri_date Library");
  Serial.print("Hasil Konversi: ");
  Serial.println(hd.getFullDate());
}

void loop() {}