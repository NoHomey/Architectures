#include <sound_color.h>
#include <animation.h>
#include "Adafruit_TLC5947.h"
#define NUM_TLC5974 8
#define data 8
#define clock 9	
#define latch 10
#define blank 11 
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch, blank);
sound_color c(5, 6, 7, 4);
animation a(8);
 
void setup() {
  Serial.begin(9600);
  tlc.begin();
}

void loop() {
  full_square();
  square();
  full_d1_up();
  full_d2_up();
  d1_up();
  d2_up();
  reverse_corners();
  corners();
  full_corners();
  reverse_full_corners();
  full_edges();
}  

void square() {
 for(int i = 0;i < 4;++i) {
   c.set();
   a.run_square(tlc, c, i);
 }
 for(int i = 3;i > -1;--i) {
   c.set();
   a.run_square(tlc, c, i);
 }
}

void full_square() {
 for(int i = 0;i < 4;++i) {
   c.set();
   a.run_full_square(tlc, c, i);
 }
 for(int i = 3;i > -1;--i) {
   c.set();
   a.run_full_square(tlc, c, i);
 }
}

void full_d1_up() {
 a.reset();
 for(int i = 0;i < 15;++i) {
   a.run_d1(i);
   c.set();
   a.write(tlc, c);
 }
 a.reset(); 
 for(int i = 14;i > -1;--i) {
   a.run_d1(i);
   c.set();
   a.write(tlc, c);
 }
}

void d1_up() {
 for(int i = 0;i < 15;++i) {
   a.reset();
   a.run_d1(i);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 14;i > -1;--i) {
   a.reset();
   a.run_d1(i);
   c.set();
   a.write(tlc, c);
 }
}

void full_d2_up() {
 a.reset();
 for(int i = 0;i < 15;++i) {
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
 a.reset(); 
 for(int i = 14;i > -1;--i) {
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
}

void d2_up() {
 for(int i = 0;i < 15;++i) {
   a.reset();
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 14;i > -1;--i) {
   a.reset();
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
}

void full_corners() {
 a.reset();
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.run_d2(i);
   a.run_d2(j);
   c.set();
   a.write(tlc, c);
 }
 a.reset();
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.run_d1(i);
   a.run_d1(j);
   c.set();
   a.write(tlc, c);
 }
}

void reverse_full_corners() {
 a.reset();
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.run_d1(i);
   a.run_d1(j);
   c.set();
   a.write(tlc, c);
 }
 a.reset();
 for(int i = 7, j = 7;i < 15, j > -1;++i,--j) {
   a.run_d1(i);
   a.run_d1(j);
   c.set();
   a.write(tlc, c);
 }
 a.reset();
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.run_d2(j);
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
 a.reset();
 for(int i = 7, j = 7;i < 15, j > -1;++i,--j) {
   a.run_d2(j);
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
}

void corners() {
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.reset();
   a.run_d2(i);
   a.run_d2(j);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.reset();
   a.run_d1(i);
   a.run_d1(j);
   c.set();
   a.write(tlc, c);
 }
}

void reverse_corners() {
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.reset();
   a.run_d1(i);
   a.run_d1(j);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 7, j = 7;i < 15, j > -1;++i,--j) {
   a.reset();
   a.run_d1(j);
   a.run_d1(i);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 0, j = 14;i < 7, j > 6;++i,--j) {
   a.reset();
   a.run_d2(j);
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 7, j = 7;i < 15, j > -1;++i,--j) {
   a.reset();
   a.run_d2(j);
   a.run_d2(i);
   c.set();
   a.write(tlc, c);
 }
}

void full_edges() {
 a.reset();
 a.run_d1(14);
 a.run_d1(0);
 a.run_d2(0);
 a.run_d2(14);
 c.set();
 a.write(tlc, c);
 a.run_d1(13);
 a.run_d1(1);
 a.run_d2(1);
 a.run_d2(13);
 c.set();
 a.write(tlc, c);
 a.run_d1(12);
 a.run_d1(2);
 a.run_d2(2);
 a.run_d2(12);
 c.set();
 a.write(tlc, c);
 a.run_d1(11);
 a.run_d1(3);
 a.run_d2(3);
 a.run_d2(11);
 c.set();
 a.write(tlc, c);
 a.run_d1(10);
 a.run_d1(4);
 a.run_d2(4);
 a.run_d2(10);
 c.set();
 a.write(tlc, c);
 a.run_d1(9);
 a.run_d1(5);
 a.run_d2(5);
 a.run_d2(9);
 c.set();
 a.write(tlc, c);
 a.run_d1(8);
 a.run_d1(6);
 a.run_d2(6);
 a.run_d2(8);
 c.set();
 a.write(tlc, c);
}
