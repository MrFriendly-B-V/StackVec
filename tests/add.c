//
// Created by tobias on 26-7-23.
//
#include "include/stackvec.h"

typedef struct Foo {
    uint32_t a;
    uint32_t b;
} Foo;

int main() {

  StackVec vec = stackvec_create(32, sizeof(Foo));

  Foo a = {
          .a = 100,
          .b = 3300,
  };

  Foo b = {
          .a = 200,
          .b = 6600,
  };

  stackvec_pushElement(&vec, &a);
  stackvec_pushElement(&vec, &b);

  Foo* a_1 = (Foo*) vec.items[0];
  if (a_1->a != 100) return -1;
  if (a_1->b != 3300) return -1;

  Foo* b_1 = (Foo*) vec.items[1];
  if (b_1->a != 200) return -1;
  if (b_1->b != 6600) return -1;


  return 0;
}