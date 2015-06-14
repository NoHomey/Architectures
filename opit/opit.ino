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
   for(int i = 0;i < 4;++i) {
     a._blue = random(4096);
     a._red = random(4096);
     a._green = random(4096);
     a.run(tlc, i);
   }
   a._blue = random(4096);
   a._red = random(4096);
   a._green = random(4096);
   a.run(tlc, 3);
   for(int i = 3;i > -1;--i) {
     a._blue = random(4096);
     a._red = random(4096);
     a._green = random(4096);
     a.run(tlc, i);
   }
}  


