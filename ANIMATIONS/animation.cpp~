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
  delay(100);
}

void animation::run_void(Adafruit_TLC5947& tlc) {
  reset();
  write(tlc);
}

void animation::run_square(Adafruit_TLC5947& tlc, const uint8_t& frame) {
  reset();
  for(uint8_t i = (_d / 2) - 1 - frame;i < (_d / 2) + 1 + frame;++i) {
    _arr[i][(_d / 2) - 1 - frame] = 1;
    _arr[i][(_d / 2) + frame] = 1;
    _arr[(_d / 2) - 1 - frame][i] = 1;
    _arr[(_d / 2) + frame][i] = 1;
  }
  write(tlc);
}

void animation::reset() {
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] = 0;
  }
}


void animation::run_full_square(Adafruit_TLC5947& tlc, const uint8_t& frame) {
  reset();
  for(uint8_t j = 0; j < frame + 1;++j) {
    for(uint8_t i = (_d / 2) - 1 - j;i < (_d / 2) + 1 + j;++i) {
      _arr[i][(_d / 2) - 1 - j] = 1;
      _arr[i][(_d / 2) + j] = 1;
      _arr[(_d / 2) - 1 - j][i] = 1;
      _arr[(_d / 2) + j][i] = 1;
    }
  }
  write(tlc);
}

void animation::run_d1(Adafruit_TLC5947& tlc, const uint8_t& frame) {
  int8_t x = frame;
  int8_t y = 0;
  while(x > -1) {
    if((y < _d) && (x < _d))
      _arr[x][y] = 1;
    x -= 1;
    y += 1;
  } 
  write(tlc);
}

void animation::run_d2(Adafruit_TLC5947& tlc, const uint8_t& frame) {
  int8_t x = frame;
  int8_t y = _d - 1;
  while(y > -1) {
    if((y > -1) && (x > -1))
      _arr[x][y] = 1;
    x -= 1;
    y -= 1;
  }
  write(tlc);
}



