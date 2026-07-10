#include "Hijri_date.h"

const char* Hijri_date::_monthNamesEnglish[] = {
  "", "Muharram", "Safar", "Rabi' al-Awwal", "Rabi' al-Thani", 
  "Jumada al-Ula", "Jumada al-Akhira", "Rajab", "Sha'ban", 
  "Ramadan", "Shawwal", "Dhu al-Qi'dah", "Dhu al-Hijjah"
};

// Konstruktor disesuaikan dengan nama class baru
Hijri_date::Hijri_date() {
  _hd = 1;
  _hm = 1;
  _hy = 1;
}

void Hijri_date::update(int d, int m, int y, int k) {
  if (m < 1 || m > 12 || d < 1 || d > 31) return;

  long jdn = (long)((1461L * (y + 4800L + (m - 14) / 12)) / 4) +
             (long)((367L * (m - 2 - 12 * ((m - 14) / 12))) / 12) -
             (long)((3 * ((y + 4900L + (m - 14) / 12) / 100)) / 4) +
             d - 32075;

  jdn += k; 

  long l = jdn - 1948440L + 10632L;
  long n = (l - 1) / 10631L;
  l = l - 10631L * n + 354L;
  long j = (long)((10985 - l) / 5316) * (long)((50 * l) / 17719) +
           (long)(l / 5670) * (long)((43 * l) / 15238);
  l = l - (long)((30 - j) / 15) * (long)((17719 * j) / 50) -
      (long)(j / 16) * (long)((15238 * j) / 43) + 29;
  
  _hm = (int)((24 * l) / 709);
  _hd = (int)(l - (709 * _hm) / 24);
  _hy = (int)(30 * n + j - 30);
}

int Hijri_date::hDay()   { return _hd; }
int Hijri_date::hMonth() { return _hm; }
int Hijri_date::hYear()  { return _hy; }

String Hijri_date::getMonthName() {
  if (_hm >= 1 && _hm <= 12) return String(_monthNamesEnglish[_hm]);
  return "Unknown";
}

String Hijri_date::getFullDate() {
  String result;
  result.reserve(30); 
  result += String(_hd);
  result += " ";
  result += getMonthName();
  result += " ";
  result += String(_hy);
  result += " H";
  return result;
}
