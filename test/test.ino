#include "game_of_life.h"
#include "Adafruit_TLC5947.h"
#define NUM_TLC5974 8
#define data   8
#define clock   9	
#define latch   10
#define blank  11 
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch, blank);
game_of_life b(8, 0);
game_of_life r(8, 1);
game_of_life g(8, 2);
void setup() {
  Serial.begin(9600);
  tlc.begin();
  b.begin(tlc);
  r.begin(tlc);
  g.begin(tlc); 
}
void loop() {
  b.progress(tlc);
  r.progress(tlc);
  g.progress(tlc);
}


