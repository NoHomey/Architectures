#ifndef _sound_color_H
#define _sound_color_H
#include <Arduino.h>
#include "Adafruit_TLC5947.h"
class sound_color {
 public:
  sound_color(const uint8_t& f1, const uint8_t& f2, const uint8_t& f3, const uint8_t& f4);
  void set(void);
  void begin(void);
  uint16_t _blue;
  uint16_t _red;
  uint16_t _green;
  uint8_t _f1;
  uint8_t _f2;
  uint8_t _f3;
  uint8_t _f4;
};
#endif
