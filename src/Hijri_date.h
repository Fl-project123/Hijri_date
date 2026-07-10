#ifndef Hijri_date_h
#define Hijri_date_h

#include "Arduino.h"

// Nama Class disamakan persis dengan nama library
class Hijri_date {
  public:
    Hijri_date();
    // d = day, m = month, y = year, k = correction/offset
    void update(int d, int m, int y, int k = 0);
    
    int hDay();
    int hMonth();
    int hYear();
    String getMonthName();
    String getFullDate();

  private:
    int _hd, _hm, _hy;
    static const char* _monthNamesEnglish[]; 
};

#endif
