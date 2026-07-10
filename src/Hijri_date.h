#ifndef Hijri_date_h
#define Hijri_date_h

#include "Arduino.h"

// Definisi konstanta untuk pilihan bahasa
#define LANG_EN 0
#define LANG_ID 1

class Hijri_date {
  public:
    Hijri_date();
    
    // d = day, m = month, y = year, k = correction/offset
    void update(int d, int m, int y, int k = 0);
    
    // Setter untuk mengubah bahasa secara global (Default: LANG_EN)
    void setLanguage(uint8_t lang);
    
    int hDay();
    int hMonth();
    int hYear();
    
    String getMonthName();
    String getFullDate();

  private:
    int _hd, _hm, _hy;
    uint8_t _currentLang; // Menyimpan status bahasa yang aktif
    
    static const char* _monthNamesEnglish[]; 
    static const char* _monthNamesIndonesia[]; 
};

#endif
