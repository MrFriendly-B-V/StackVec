//
// Created by tobias on 26-7-23.
//
#include <time.h>
#include "include/stackvec.h"

typedef struct Foo {
    uint32_t a;
    uint32_t b;
} Foo;

void waitFor (unsigned int secs) {
  unsigned int retTime = time(0) + secs;   // Get finishing time.
  while (time(0) < retTime);               // Loop until it arrives.
}


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

  stackvec_removeElement(&vec, 1);

  if(vec.lastItem != 0) return -1;

  stackvec_pushElement(&vec, &b);
  stackvec_removeElement(&vec, 0); // Remove A, B becomes 0

  if(vec.lastItem != 0) return -1;

  Foo* b_1 = (Foo*) vec.items[0];
  if(b_1->a != 200) return -2;

  stackvec_removeElement(&vec, 0);

  return 0;
}