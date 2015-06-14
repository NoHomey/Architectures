#include <game_of_life.h>

game_of_life::game_of_life(const uint8_t& d, const uint8_t& col) {
  _d = d;
  _arr = (bool**) calloc(_d, sizeof(bool*));
  _pwm = 0;
  _color = col;
  for(int8_t i = 0;i < _d;++i)
    _arr[i] = (bool*) calloc(_d, sizeof(bool));
}

game_of_life::~game_of_life() {
  for(int8_t i = 0;i < _d;++i)
    free(_arr[i]);
  free(_arr);
}

uint16_t game_of_life::convert(const uint8_t& x, const uint8_t& y) {
  return (x*_d + y)*3 + _color;
}

void game_of_life::write(Adafruit_TLC5947& tlc) {
  _pwm = random(4096);
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] ? tlc.setPWM(convert(i, j), _pwm) : tlc.setPWM(convert(i, j), 0);
  }
  tlc.write();
}

void game_of_life::reset(Adafruit_TLC5947& tlc) {
  for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j)
      _arr[i][j] = 0;
  }
  write(tlc);
  begin(tlc);
}

void game_of_life::begin(Adafruit_TLC5947& tlc) {
  uint8_t s = 50;
  for(int8_t i = 0;i < s;++i)
    _arr[random(_d)][random(_d)] = 1;
  write(tlc);  	
}

void game_of_life::progress(Adafruit_TLC5947& tlc) {
  int8_t flag = 0;
   int8_t neibrs = 0;
   for(int8_t i = 0;i < _d;++i) {
    for(int8_t j = 0;j < _d;++j) {
      neibrs = 0;
      neibrs += (((i - 1) < 0) ||  ((j - 1) < 0)) ? 0 : _arr[i - 1][j - 1];
      neibrs += ((i - 1) < 0) ? 0 : _arr[i - 1][j];
      neibrs += (((i - 1) < 0) ||  ((j + 1) > 7)) ? 0 : _arr[i - 1][j + 1];
      neibrs += ((j + 1) > 7) ? 0 : _arr[i][j + 1];
      neibrs += (((i + 1) > 7) ||  ((j + 1) > 7)) ? 0 : _arr[i + 1][j + 1];
      neibrs += ((i + 1) > 7) ? 0 : _arr[i + 1][j];
      neibrs += (((i + 1) > 7) ||  ((j - 1) < 7)) ? 0 : _arr[i + 1][j - 1];
      neibrs += ((j - 1) < 0) ? 0 : _arr[i][j - 1];
      if((neibrs == 3) && !_arr[i][j]){
      	_arr[i][j] = 1;
      	flag = 1;
      }
      if(((neibrs > 3) || (neibrs < 2)) && _arr[i][j]) {
      	_arr[i][j] = 0;
      	flag = 1;
      }
    }
  }
  Serial.println(flag);
  flag ? write(tlc) : reset(tlc);
}
