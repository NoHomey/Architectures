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

void animation::run_game_of_life(Adafruit_TLC5947& tlc, const uint8_t& frame, uint8_t flag) {
  if(!frame) {
    reset();
    _arr[0][7] = 1;
    _arr[0][6] = 1;
    _arr[1][7] = 1;
    _arr[2][4] = 1;
    _arr[3][4] = 1;
    _arr[3][5] = 1;
    _arr[0][1] = 1;
    _arr[1][1] = 1;
    _arr[2][1] = 1;
    _arr[6][6] = 1;
    _arr[7][6] = 1;
    _arr[7][7] = 1;
    _arr[5][0] = 1;
    _arr[4][1] = 1;
    _arr[4][2] = 1;
    _arr[7][1] = 1;
    _arr[7][2] = 1;
    _arr[6][3] = 1;
  } else {
    uint8_t neibrs = 0;
    flag = 0;
    for (int8_t i=0;i < _d;++i) for (int8_t j=0;j < _d;++j) {
        neibrs = 0;
        for (int8_t k = i - 1; k < i + 2;++k) for (int8_t l= j - 1;l < j + 2;++l)
          if((((k > -1) && (k < _d)) && ((l > -1) && (l < _d))) && _arr[k][l])
            neibrs++;
        if(neibrs == 3) {
           _arr[i][j] = 1;
           flag = 1;
        }
        if((neibrs < 2) || (neibrs > 3)) {
          _arr[i][j] = 0;
          flag = 1;
        }
    }
  }
  write(tlc);
}


