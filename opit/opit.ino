#include <animation.h>


#include "Adafruit_TLC5947.h"
#define NUM_TLC5974 8
#define data 8
#define clock 9	
#define latch 10
#define blank 11 
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch, blank);
animation a(8);
 
void setup() {
  Serial.begin(9600);
  tlc.begin();
}

void loop() {
  square();
  a.run_void(tlc);
  full_square();
  a.run_void(tlc);
 // game_of_life();
  //a.run_void(tlc);
}  

void square() {
 a._blue = 0;
 a._red = 5000;
 a._green = 1200;
 for(int i = 0;i < 4;++i)
   a.run_square(tlc, i);
 for(int i = 3;i > -1;--i)
   a.run_square(tlc, i);
}

void full_square() {
 a._blue = 500;
 a._red = 5000;
 a._green = 200;
 for(int i = 0;i < 4;++i)
   a.run_full_square(tlc, i);
 for(int i = 3;i > -1;--i)
   a.run_full_square(tlc, i);
}

void game_of_life () {

  uint8_t flag = 1;
  for(int i = 0;flag && i < 10;++i) {
     a._blue = random(4096);
     a._red = random(4096);
     a._green = random(4096);
     a.run_game_of_life(tlc, i, flag);
   }
  
}
