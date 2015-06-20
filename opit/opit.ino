#include <sound_color.h>
#include <animation.h>
#include "Adafruit_TLC5947.h"
Adafruit_TLC5947 tlc = Adafruit_TLC5947(8);
sound_color c(5, 6, 7, 4);
animation a(8);
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  full_square();
  square();
  cross();
  transform();
  a_up();
  b_up();
  a_down();
  b_down();
  d2_up();
  d1_up();
  corners();
  reverse_corners();
  full_d1_up();
  full_d2_up();
  full_corners();
  reverse_full_corners();
  full_b_up();
  full_b_down();
  full_a_up();
  full_a_down();
  full_transform();
  full_cross();
  full_edges();
  havycross();
  clearscr();
}  

void square() {
 for(int i = 0;i < 4;++i) {
   a.reset();
   c.set();
   a.run_square(i);
   a.write(tlc, c);
 }
 for(int i = 3;i > -1;--i) {
   a.reset();
   c.set();
   a.run_square(i);
   a.write(tlc, c);
 }
}

void full_square() {
 for(int i = 0;i < 4;++i) {
   a.reset();
   for(int j = 0;j < i + 1;++j)
     a.run_square(j);
   c.set();
   a.write(tlc, c);
 }
 for(int i = 3;i > -1;--i) {
   a.reset();
   for(int j = 0;j < i + 1;++j)
     a.run_square(j);
   c.set();
   a.write(tlc, c);
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
 for(uint8_t i = 0;i < 7;++i) {
   a.reset();
   set_edges(i);
   c.set();
   a.write(tlc, c);
 }
 a.reset();
 for(uint8_t i = 0;i < 7;++i) {
   set_edges(i);
   c.set();
   a.write(tlc, c);
 }
}

void set_edges(uint8_t f) {
 a.run_d1(14 - f);
 a.run_d1(f);
 a.run_d2(f);
 a.run_d2(14 - f);
}

void full_a_up() {
  a.reset();
  for(int8_t i = 0;i < 8;++i) {
   a.run_a(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 7;i > -1;--i) {
   a.run_a(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void a_up() {
  for(int8_t i = 0;i < 8;++i) {
   a.reset();
   a.run_a(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 7;i > -1;--i) {
   a.reset();
   a.run_a(i, 1);
   c.set();
   a.write(tlc, c);
 }
}

void full_a_down() {
  a.reset();
 for(int8_t i = 7;i > -1;--i) {
   a.run_a(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 0;i < 8;++i) {
   a.run_a(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void a_down() {
 for(int8_t i = 7;i > -1;--i) {
   a.reset();
   a.run_a(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 0;i < 8;++i) {
   a.reset();
   a.run_a(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void full_b_up() {
  a.reset();
  for(int8_t i = 0;i < 8;++i) {
   a.run_b(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 7;i > -1;--i) {
   a.run_b(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void b_up() {
  for(int8_t i = 0;i < 8;++i) {
   a.reset();
   a.run_b(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 7;i > -1;--i) {
   a.reset();
   a.run_b(i, 1);
   c.set();
   a.write(tlc, c);
 }
}

void full_b_down() {
  a.reset();
 for(int8_t i = 7;i > -1;--i) {
   a.run_b(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 0;i < 8;++i) {
   a.run_b(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void b_down() {
 for(int8_t i = 7;i > -1;--i) {
   a.reset();
   a.run_b(i, 1);
   c.set();
   a.write(tlc, c);
 }
 for(int8_t i = 0;i < 8;++i) {
   a.reset();
   a.run_b(i, 0);
   c.set();
   a.write(tlc, c);
 }
}

void full_transform() {
   a.reset();
   for(int8_t i = 0;i < 8;++i) {
     a.run_b(i, 1);
     a.run_a(i, 1);
     c.set();
     a.write(tlc, c);
 }
  a.reset();
  for(int8_t i = 7;i > -1;--i) {
   a.run_b(i, 1);
   a.run_a(i, 1);
   a.run_b(0 + i, 1);
   a.run_a(0 + i, 1);
   c.set();
   a.write(tlc, c);
  } 
}

void transform() {
   for(int8_t i = 0;i < 8;++i) {
     a.reset();
     a.run_b(i, 1);
     a.run_a(i, 1);
     c.set();
     a.write(tlc, c);
 }
  for(int8_t i = 7;i > -1;--i) {
   a.reset();
   a.run_b(i, 1);
   a.run_a(i, 1);
   a.run_b(0 + i, 1);
   a.run_a(0 + i, 1);
   c.set();
   a.write(tlc, c);
  } 
}

void full_cross() {
  a.reset();
  for(int8_t i = 0;i < 8;++i) {
   a.run_b(i, 1);
   a.run_a(i, 1);
   a.run_b(7 - i, 1);
   a.run_a(7 - i, 1);
   c.set();
   a.write(tlc, c);
  } 
}

void cross() {
  for(int8_t i = 0;i < 8;++i) {
   a.reset();
   a.run_b(i, 1);
   a.run_a(i, 1);
   a.run_b(7 - i, 1);
   a.run_a(7 - i, 1);
   c.set();
   a.write(tlc, c);
  } 
}

void havycross() {
  clearscr();
  for(int8_t i = 0;i < 4;++i) {
   a.reset();
   a.run_havycross(i, 1);
   c.set();
   a.write(tlc, c);
  } 
  for(int8_t i = 3;i > -1;--i) {
   a.reset();
   a.run_havycross(i, 0);
   c.set();
   a.write(tlc, c);
  }
  clearscr();
}

void clearscr() {
  a.reset();
  a.write(tlc, c); 
}
