#include <animation.h>

sound_color::sound_color(const uint8_t& f1, const uint8_t& f2, const uint8_t& f3, const uint8_t& f4)
: _blue(0), _red(0), _green(0), _yellow(0), _f1(f1), _f2(f2), _f3(f3), _f4(f4) {
  analogReference(INTERNAL);
  pinMode(_f1, INPUT);
  pinMode(_f2, INPUT);
  pinMode(_f3, INPUT);
  pinMode(_f4, INPUT);  
}

void sound_color::set() {
   uint16_t b, r, g, y;
   b = analogRead(_f1);
   b = b < 5 ? 0 : b;
   g = analogRead(_f2);
   g = g < 3 ? 0 : g;
   r = analogRead(_f3);
   r = r < 7 ? 0 : r;
   y = analogRead(_f4);
   y = y < 7 ? 0 : y;
  _yellow = y * 1.5;
  _blue = b * 13;
  _red = r * 1.5;
  _green = g * 23;
}
