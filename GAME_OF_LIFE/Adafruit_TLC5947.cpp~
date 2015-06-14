#include <Adafruit_TLC5947.h>

Adafruit_TLC5947::Adafruit_TLC5947(const uint8_t& n, const uint8_t& c, const uint8_t& d, const uint8_t& l, const uint8_t& b = -1) {
  num = n;
  _clk = c;
  _dat = d;
  _lat = l;
  _blk = b;
  pwmbuffer = (uint16_t *)calloc(24*n, sizeof(uint16_t));
}

Adafruit_TLC5947::~Adafruit_TLC5947(void) {
  free(pwmbuffer);
}

void Adafruit_TLC5947::write(void) {
  if(_blk > -1)
    digitalWrite(_blk, LOW);
  digitalWrite(_lat, LOW);
  for (int16_t c = 24*num - 1;c >= 0;--c) {
    for (int8_t b=11; b>=0; b--) {
      digitalWrite(_clk, LOW);
      (pwmbuffer[c] & (1 << b)) ? digitalWrite(_dat, HIGH) : digitalWrite(_dat, LOW);
      digitalWrite(_clk, HIGH);
    }
  }
  digitalWrite(_clk, LOW);
  digitalWrite(_lat, HIGH);  
  digitalWrite(_lat, LOW);
}

void Adafruit_TLC5947::setPWM(const uint16_t& chan, const uint16_t& pwm) {
  uint16_t val;
  val = pwm > 4095 ? 4095 : pwm;
  if (chan > 24*num) return;
  pwmbuffer[chan] = val;  
}

void Adafruit_TLC5947::setLED(const uint8_t& lednum, const uint16_t& b, const uint16_t& r, const uint16_t& g) {
  setPWM(lednum*3, b);
  setPWM(lednum*3+1, r);
  setPWM(lednum*3+2, g);
}

boolean Adafruit_TLC5947::begin() {
  if (!pwmbuffer) return false;
  pinMode(_clk, OUTPUT);
  pinMode(_dat, OUTPUT);
  pinMode(_lat, OUTPUT);
  if(_blk > -1) {
    pinMode(_blk, OUTPUT);
    digitalWrite(_blk, HIGH);
  }
  return true;
}
