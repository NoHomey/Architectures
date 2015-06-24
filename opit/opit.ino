#include <sound_color.h>
#include <animation.h>
#include "Adafruit_TLC5947.h"
Adafruit_TLC5947 tlc = Adafruit_TLC5947(8);
sound_color c(0, 1, 2, 3);
animation a(8);

#define d 8

void setup() {
  Serial.begin(9600);
}

void loop() {
  square();
  edges();;
  cross();
  transform();
  a_up();
  b_up();
  a_down();
  b_down();
  d2_up();;
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
  int i = 0;
  while(i < 1000) {
    a.write4(tlc, c);
    i++;
  }
}  

void square() {
  c.set();
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    a.run_square(i);
    a.write(tlc, c);
  }
  for(int8_t i = (d / 2) - 1;i > -1;--i) {
    a.reset();
    a.run_square(i);
    a.write(tlc, c);
  }
}

void full_square() {
  c.set();
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    for(int8_t j = 0;j < i + 1;++j)
      a.run_square(j);
    a.write(tlc, c);
  }
for(int8_t i = (d / 2) - 1;i > -1;--i) {
    a.reset();
    for(int8_t j = 0;j < i + 1;++j)
      a.run_square(j);
    a.write(tlc, c);
  }
}

void full_d1_up() {
  c.set();
  a.reset();
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.run_d1(i);
    a.write(tlc, c);
  }
  a.reset(); 
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.run_d1(i);
    a.write(tlc, c);
  }
}

void d1_up() {
  c.set();
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
  c.set();
  a.reset();
  for(int8_t i = 0;i < (d * 2) - 1;++i) {
    a.run_d2(i);
    a.write(tlc, c);
  }
  a.reset(); 
  for(int8_t i = (d * 2) - 2;i > -1;--i) {
    a.run_d2(i);
    a.write(tlc, c);
  }
}

void d2_up() {
  c.set();
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
  c.set();
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d2(i);
    a.run_d2(j);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c);
  }
}

void reverse_full_corners() {
  c.set();
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 2, j > d - 1;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c);
  }
}

void corners() {
  c.set();
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d2(i);
    a.run_d2(j);
    a.write(tlc, c);
  }
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c);
  }
}

void reverse_corners() {
  c.set();
 for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d1(i);
    a.run_d1(j);
    a.write(tlc, c);
  }
  for(int8_t i = d- 1, j = d- 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.reset();
    a.run_d1(j);
    a.run_d1(i);
    a.write(tlc, c);
  }
  for(int8_t i = 0, j = (d * 2) - 2;i < d - 1, j > d - 2;++i,--j) {
    a.reset();
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1, j = d - 1;i < (d * 2) - 1, j > -1;++i,--j) {
    a.reset();
    a.run_d2(j);
    a.run_d2(i);
    a.write(tlc, c);
  }
}

void full_edges() {
  c.set();
  a.reset();
  for(int8_t i = 0;i < d - 1;++i) {
    set_edges(i);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = d - 3;i > -1;--i) {
    set_edges(i);
    a.write(tlc, c);
  }
  clearscr();
}

void edges() {
  c.set();
  for(int8_t i = 0;i < d - 1;++i) {
    a.reset();
    set_edges(i);
    a.write(tlc, c);
  }
  for(int8_t i = d - 3;i > -1;--i) {
    a.reset();
    set_edges(i);
    a.write(tlc, c);
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
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
  c.set();
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  a.reset();
  for(int8_t i = d - 1;i > -1;--i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(0 + i, 1);
    a.run_a(0 + i, 1);
    a.write(tlc, c);
  } 
}

void transform() {
  c.set();
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.write(tlc, c);
  }
  for(int8_t i = d - 1;i > -1;--i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(0 + i, 1);
    a.run_a(0 + i, 1);
    a.write(tlc, c);
  } 
}

void full_cross() {
  c.set();
  a.reset();
  for(int8_t i = 0;i < d;++i) {
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(d - 1 - i, 1);
    a.run_a(d - 1 - i, 1);
    a.write(tlc, c);
  } 
}

void cross() {
  c.set();
  for(int8_t i = 0;i < d;++i) {
    a.reset();
    a.run_b(i, 1);
    a.run_a(i, 1);
    a.run_b(d - 1 - i, 1);
    a.run_a(d - 1 - i, 1);
    a.write(tlc, c);
  } 
}

void havycross() {
  c.set();
  clearscr();
  for(int8_t i = 0;i < d / 2;++i) {
    a.reset();
    a.run_havycross(i, 1);
    a.write(tlc, c);
  } 
  for(int8_t i = (d / 2 ) - 1;i > -1;--i) {
    a.reset();
    a.run_havycross(i, 0);
    a.write(tlc, c);
  }
  clearscr();
}

void clearscr() {
  a.reset();
  a.write(tlc, c); 
}
