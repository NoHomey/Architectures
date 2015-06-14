#ifndef _ADAFRUIT_TLC5947_H
#define _ADAFRUIT_TLC5947_H

#include <Arduino.h>

class Adafruit_TLC5947 {
 public:
  Adafruit_TLC5947(const uint8_t& n, const uint8_t& c, const uint8_t& d, const uint8_t& l, const uint8_t& b);
  ~Adafruit_TLC5947(void);
  boolean begin(void);
  void setPWM(const uint16_t& chan, const uint16_t& pwm);
  void setLED(const uint8_t& lednum, const uint16_t& b, const uint16_t& r, const uint16_t& g);
  void write(void);
 private:
  uint16_t *pwmbuffer;
  uint8_t num, _clk, _dat, _lat, _blk;
};

#endif
