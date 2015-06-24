#include <animation.h>

animation::animation(const uint8_t& d)
: _d(d) {
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

void animation::write(Adafruit_TLC5947& tlc, sound_color& c) {
  for(int8_t i = 0;i < _d;++i) 
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] ? tlc.setLED(convert(i, j), 11 * c._blue, 11 * (c._red + 1.5 * c._yellow), 11 * (c._green + c._yellow / 2)) : tlc.setLED(convert(i, j), 0, 0, 0);
  tlc.write();	
  delay(36);
}

void animation::reset() {
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] = 0;
  }
}

void animation::run_square(const uint8_t& frame) {
  for(uint8_t i = (_d / 2) - 1 - frame;i < (_d / 2) + 1 + frame;++i) {
    _arr[i][(_d / 2) - 1 - frame] = 1;
    _arr[i][(_d / 2) + frame] = 1;
    _arr[(_d / 2) - 1 - frame][i] = 1;
    _arr[(_d / 2) + frame][i] = 1;
  }
}

void animation::run_d1(const uint8_t& frame) {
  int8_t x = frame;
  int8_t y = 0;
  while(x > -1) {
    if((y < _d) && (x < _d))
      _arr[x][y] = 1;
    x -= 1;
    y += 1;
  } 
}

void animation::run_d2(const uint8_t& frame) {
  int8_t x = frame;
  int8_t y = _d - 1;
  while(y > -1) {
    if((y > -1) && (x > -1))
      _arr[x][y] = 1;
    x -= 1;
    y -= 1;
  }
}

void animation::run_a(const uint8_t& frame, const bool& val) {
  for(int8_t i = 0; i < _d;++i)
    _arr[frame][i] = val;
}

void animation::run_b(const uint8_t& frame, const bool& val) {
  for(int8_t i = 0; i < _d;++i)
    _arr[i][frame] = val;
}

void animation::run_havycross(const uint8_t& frame, const bool& val) {
  for(int8_t i = (_d / 2) - 1 - frame;i < (_d / 2) + 1 + frame;++i) {
    for(int8_t j = 0;j < _d;++j) {
      _arr[i][j] = 1;
      _arr[j][i] = 1;
    }
  } 
}

void animation::write4(Adafruit_TLC5947& tlc, sound_color& c) {
   c.set();
   float k = 0.1;
   float l = 1;
   for(int8_t i = _d / 2 - 1;i > -1;--i) 
    for(int8_t j = _d / 2 - 1;j > - 1;--j)
      tlc.setLED(convert(i, j), (k += 0.1) * (l += 0.5) * c._blue , 0 , 0);
    k = 0.1;
    l = 1;
    for(int8_t i = _d / 2;i < _d;++i) 
      for(int8_t j = _d / 2;j < _d;++j)
        tlc.setLED(convert(i, j), 0, (k += 0.1) * (l += 0.5) * c._red, 0);
    k = 0.1;
    l = 1;
    for(int8_t i = _d / 2;i < _d;++i) 
      for(int8_t j = _d / 2 - 1;j > -1;--j) {
        (k += 0.1) * (l += 0.5);
        tlc.setLED(convert(i, j), 0, k * l * 3 * c._yellow, k * l * c._yellow);
    }
    k = 0.1;
    l = 1;
    for(int8_t i = _d / 2 - 1;i > -1;--i) 
      for(int8_t j = _d / 2;j < _d;++j)
        tlc.setLED(convert(i, j), 0, 0, (k += 0.1) * (l += 0.5) * c._green);
    tlc.write();
}
