#ifndef _ADAFRUIT_TLC5947_H
#define _ADAFRUIT_TLC5947_H
#define _PORT_TLC5947 PORTB
#define _REGISTER_TLC5947 DDRB
#define _SETUP_TLC5947 B0001111
#define _DATA_TLC5947 PB0
#define _CLOCK_TLC5947 PB1
#define _LATCH_TLC5947 PB2
#include <Arduino.h>
class Adafruit_TLC5947 {
 public:
  Adafruit_TLC5947(const uint8_t& n);
  ~Adafruit_TLC5947(void);	
  void setPWM(const uint16_t& chan, const uint16_t& pwm);
  void setLED(const uint8_t& lednum, const uint16_t& b, const uint16_t& r, const uint16_t& g);
  void write(void);
 private:
  uint16_t *pwmbuffer;
  uint8_t num;
};
#endif
