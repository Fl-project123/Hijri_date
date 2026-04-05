#ifndef Hijri_date_h
#define Hijri_date_h

#include "Arduino.h"

class HijriDate {
  public:
    HijriDate();
    // d = day, m = month, y = year, k = correction/offset
    void update(int d, int m, int y, int k = 0);
    
    int hDay();
    int hMonth();
    int hYear();
    String getMonthName();
    String getFullDate();

  private:
    int _hd, _hm, _hy;
    // Kita deklarasikan saja variabelnya di sini tanpa isinya
    static const char* _monthNamesEnglish[]; 
};

#endif