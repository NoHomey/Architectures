#include <animation.h>

sound_color::sound_color(const uint8_t& f1, const uint8_t& f2, const uint8_t& f3, const uint8_t& f4)
: _blue(0), _red(0), _green(0), _f1(f1), _f2(f2), _f3(f3), _f4(f4) {}

void sound_color::set() {
  _blue = 4096;
  _red = 0;
  _green = 0;
}

void sound_color::begin() {
  pinMode(_f1, INPUT);
  pinMode(_f2, INPUT);
  pinMode(_f3, INPUT);
  pinMode(_f4, INPUT);  
}
