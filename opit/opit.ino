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
  full_square();
  full_d1_up();
  d1_up();
  full_d2_up();
  d2_up();
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

void full_d1_up() {
 a._blue = 5000;
 a._red = 0;
 a._green = 0;
 a.reset();
 for(int i = 0;i < 15;++i)
   a.run_d1(tlc, i);
 a.reset(); 
 for(int i = 14;i > -1;--i)
   a.run_d1(tlc, i);
}

void d1_up() {
 a._blue = 0;
 a._red = 0;
 a._green = 5000;
 for(int i = 0;i < 15;++i) {
   a.reset();
   a.run_d1(tlc, i);
 }
 for(int i = 14;i > -1;--i) {
   a.reset();
   a.run_d1(tlc, i);
 }
}

void full_d2_up() {
 a._blue = 5000;
 a._red = 5000;
 a._green = 0;
 a.reset();
 for(int i = 0;i < 15;++i)
   a.run_d2(tlc, i);
 a.reset(); 
 for(int i = 14;i > -1;--i)
   a.run_d2(tlc, i);
}

void d2_up() {
 a._blue = 0;
 a._red = 5000;
 a._green = 0;
 for(int i = 0;i < 15;++i) {
   a.reset();
   a.run_d2(tlc, i);
 }
 for(int i = 14;i > -1;--i) {
   a.reset();
   a.run_d2(tlc, i);
 }
}
