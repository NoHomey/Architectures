#include "Adafruit_TLC5947.h"
#include "game_of_life.h"
#define NUM_TLC5974 8
#define data   8
#define clock   9
#define latch   10
#define blank  11 
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch, blank);
game_of_life b(8, &tlc, 0);
game_of_life r(8, &tlc, 1);
game_of_life g(8, &tlc, 2);
void setup() {
  Serial.begin(9600);
  tlc.begin();
  b.begin();
  r.begin();
  g.begin(); 
}
void loop() {
  delay(300);
  b.progress();
  r.progress();
  g.progress();
  delay(300);
}


