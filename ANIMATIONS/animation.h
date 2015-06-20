#ifndef _animation_H
#define _animation_H
#include <Arduino.h>
#include "Adafruit_TLC5947.h"
#include "sound_color.h"
class animation {
 public:
  animation(const uint8_t& d);
  ~animation(void);
  void reset();
  void write(Adafruit_TLC5947& tlc, const sound_color& c);
  void run_square(const uint8_t& frame);
  void run_d1(const uint8_t& frame);
  void run_d2(const uint8_t& frame);
  uint16_t convert(const uint8_t& x, const uint8_t& y);
 private:
  uint8_t _d;
  bool** _arr;
};
#endif
