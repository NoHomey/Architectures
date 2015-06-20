#include <sound_color.h>
#include <animation.h>
#include "Adafruit_TLC5947.h"
Adafruit_TLC5947 tlc = Adafruit_TLC5947(8);
sound_color c(5, 6, 7, 4);
animation a(8);

#define d 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  square();
  edges();
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
  full_square();
}  

void square() {
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    a.run_square(i);
    a.write(tlc, c, 75);
  }
  for(int8_t i = (d / 2) - 1;i > -1;--i) {
    a.reset();
    a.run_square(i);
    a.write(tlc, c, 75);
  }
}

void full_square() {
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    for(int8_t j = 0;j < i + 1;++j)
      a.run_square(j);
    a.write(tlc, c, 75);
  }
for(int8_t i = (d / 2) - 1;i > -1;--i) {
    a.reset();
    for(int8_t j = 0;j < i + 1;++j)
      a.run_square(j);
    a.write(tlc, c, 75);
  }
}

void full_d1_up() {
  a.reset();
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.run_d1(i);
    a.write(tlc, c, 45);
  }
  a.reset(); 
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.run_d1(i);
    a.write(tlc, c, 45);
  }
}

void d1_up() {
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.reset();
    a.run_d1(i);
    a.write(tlc, c);
  }
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.reset();
    a.run_d1(i);
    a.write(tlc, c);
  }
}

void full_d2_up() {
  a.reset();
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.run_d2(i);
    a.write(tlc, c, 45);
  }
  a.reset(); 
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.run_d2(i);
    a.write(tlc, c, 45);
  }
}

void d2_up() {
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.reset();
    a.run_d2(i);
    a.write(tlc, c);
  }
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.reset();
    a.run_d2(i);
    a.write(tlc, c);
  }
}

void full_corners() {
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d2(i);
    a.run_d2(j);
    a.write(tlc, c, 50);
  }
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c, 50);
  }
}

void reverse_full_corners() {
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 2, j > d - 1;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c, 50);
  }
  a.reset();
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c, 50);
  }
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c, 50);
  }
  a.reset();
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c, 50);
  }
}

void corners() {
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d2(i);
    a.run_d2(j);
    a.write(tlc, c, 50);
  }
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c, 50);
  }
}

void reverse_corners() {
 for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c, 50);
  }
  for(int8_t i = d- 1, j = d- 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.reset();
    a.run_d1(j);
    a.run_d1(i);
    a.write(tlc, c, 50);
  }
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c, 50);
  }
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.reset();
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c, 50);
  }
}

void full_edges() {
  a.reset();
  for(int8_t i = 0;i < d - 1;++i) {
    set_edges(i);
    a.write(tlc, c, 75);
  }
  a.reset();
  for(int8_t i = d - 3;i > -1;--i) {
    set_edges(i);
    a.write(tlc, c, 75);
  }
  clearscr();
}

void edges() {
  for(int8_t i = 0;i < d - 1;++i) {
    a.reset();
    set_edges(i);
    a.write(tlc, c, 75);
  }
  for(int8_t i = d - 3;i > -1;--i) {
    a.reset();
    set_edges(i);
    a.write(tlc, c, 75);
  }
  clearscr();
}

void set_edges(uint8_t f) {
  a.run_d1(14 - f);
  a.run_d1(f);
  a.run_d2(f);
  a.run_d2(14 - f);
}

void full_a_up() {
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_a(i, 0);
    a.write(tlc, c);
  }
}

void a_up() {
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_a(i, 1);
    a.write(tlc, c);
  }
}

void full_a_down() {
  a.reset();
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = 0;i < d;++i) {
    a.run_a(i, 0);
    a.write(tlc, c);
  }
}

void a_down() {
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_a(i, 0);
    a.write(tlc, c);
  }
}

void full_b_up() {
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_b(i, 0);
    a.write(tlc, c);
  }
}

void b_up() {
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_b(i, 1);
    a.write(tlc, c);
  }
}

void full_b_down() {
  a.reset();
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_b(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 0);
    a.write(tlc, c);
  }
}

void b_down() {
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_b(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 0);
    a.write(tlc, c);
  }
}

void full_transform() {
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.write(tlc, c, 75);
  }
  a.reset();
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(0 + i, 1);
    a.run_a(0 + i, 1);
    a.write(tlc, c, 75);
  } 
}

void transform() {
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.write(tlc, c, 50);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(0 + i, 1);
    a.run_a(0 + i, 1);
    a.write(tlc, c, 50);
  } 
}

void full_cross() {
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(d - 1 - i, 1);
    a.run_a(d - 1 - i, 1);
    a.write(tlc, c, 75);
  } 
}

void cross() {
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(d - 1 - i, 1);
    a.run_a(d - 1 - i, 1);
    a.write(tlc, c, 75);
  } 
}

void havycross() {
  clearscr();
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    a.run_havycross(i, 1);
    a.write(tlc, c, 75);
  } 
  for(int8_t i = (d / 2 ) - 1;i > -1;--i) {
    a.reset();
    a.run_havycross(i, 0);
    a.write(tlc, c, 75);
  }
  clearscr();
}

void clearscr() {
  a.reset();
  a.write(tlc, c); 
}
