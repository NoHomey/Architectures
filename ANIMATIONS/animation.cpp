#include <animation.h>

animation::animation(const uint8_t& d)
: _d(d), _blue(0), _red(0), _green(0) {
  _arr = (bool**) calloc(_d, sizeof(bool*));
  for(int8_t i = 0;i < _d;++i)
    _arr[i] = (bool*) calloc(_d, sizeof(bool));
}

animation::~animation() {
  for(int8_t i = 0;i < _d;++i)
    free(_arr[i]);
  free(_arr);
}

uint16_t animation::convert(const uint8_t& x, const uint8_t& y) {
  return (x*_d + y);
}

void animation::write(Adafruit_TLC5947& tlc) {
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] ? tlc.setLED(convert(i, j), _blue, _red, _green) : tlc.setLED(convert(i, j), 0, 0, 0);
  }
  tlc.write();	
}

void animation::run(Adafruit_TLC5947& tlc, const uint8_t& frame) {
  run_frame(frame);
  write(tlc);
}

void animation::run_frame(const uint8_t& frame) {
  reset();
  for(uint8_t i = (_d / 2) - 1 - frame;i < (_d / 2) + 1 + frame;++i) {
        _arr[i][(_d / 2) - 1 - frame] = 1;
        _arr[i][(_d / 2) + 1 + frame] = 1;
        _arr[(_d / 2) - 1 - frame][i] = 1;
        _arr[(_d / 2) + 1 + frame][i] = 1;
      }
}

void animation::reset() {
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] = 0;
  }
}
