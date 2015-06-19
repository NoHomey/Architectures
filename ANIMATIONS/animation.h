#ifndef _animation_H
#define _animation_H
#include <Arduino.h>
#include "Adafruit_TLC5947.h"
class animation {
 public:
  animation(const uint8_t& d);
  ~animation(void);
  void write(Adafruit_TLC5947& tlc);
  void run(Adafruit_TLC5947& tlc, const uint8_t& frame);
  void run_square(Adafruit_TLC5947& tlc, const uint8_t& frame);
  void run_d1(Adafruit_TLC5947& tlc, const uint8_t& frame);
  void run_d2(Adafruit_TLC5947& tlc, const uint8_t& frame);
  void run_full_square(Adafruit_TLC5947& tlc, const uint8_t& frame);
  void run_void(Adafruit_TLC5947& tlc);
  void reset();
  uint16_t convert(const uint8_t& x, const uint8_t& y);
  uint16_t _blue;
  uint16_t _red;
  uint16_t _green;
 private:
  uint8_t _d;
  bool** _arr;
};
#endif
