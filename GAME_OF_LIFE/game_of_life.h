#ifndef _GAME_OF_LIFE_H
#define _GAME_OF_LIFE_H
#include <Arduino.h>
#include "Adafruit_TLC5947.h"
class game_of_life {
 public:
  game_of_life(const uint8_t& d, const uint8_t& col);
  ~game_of_life(void);
  void progress(Adafruit_TLC5947& tlc);
  void write(Adafruit_TLC5947& tlc);
  void reset(Adafruit_TLC5947& tlc);
  void begin(Adafruit_TLC5947& tlc);
  uint16_t convert(const uint8_t& x, const uint8_t& y);
 private:
  uint8_t _d;
  bool** _arr;
  uint16_t _pwm;
  uint8_t _color;
};
#endif
