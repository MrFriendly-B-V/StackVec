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

  if(vec.item_size != 8) return -1;
  if(vec.max != 32) return -1;
  if(vec.lastItem != -1) return -1;

  return 0;
}