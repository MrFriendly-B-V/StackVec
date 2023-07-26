#include "include/stackvec.h"

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

StackVec stackvec_create(size_t max, size_t item_size) {
  void* items[item_size * max];

  // Initialize the list to NULL
  for(uint32_t index = 0; index < max; index++) {
    items[index] = NULL;
  }

  StackVec stackVec = {
          .items = items,
          .lastItem = -1,
          .max = max,
          .item_size = item_size,
  };

  return stackVec;
}

bool stackvec_pushElement(StackVec* vec, void* item) {
  if(vec->lastItem + 1 > vec->max) {
    return false;
  }

  int32_t nextIndex = vec->lastItem + 1;
  vec->items[nextIndex] = item;
  vec->lastItem = nextIndex;

  return true;
}

bool stackvec_removeElement(StackVec* vec, size_t index) {
  if(index > vec->lastItem) {
    return false;
  }

  // Overwrite the element by shifting everything
  for(uint32_t idx = index; idx < vec->lastItem; idx++) {
    vec->items[idx] = vec->items[idx + 1];
  }

  // Overwrite the previous last element with NULL
  vec->items[vec->lastItem] = NULL;
  vec->lastItem = vec->lastItem - 1;

  return true;
}

void* stackvec_front(StackVec* vec) {
  if(vec->lastItem < 0) {
    return NULL;
  }

  return vec->items[0];
}

void* stackvec_back(StackVec* vec) {
  if(vec->lastItem < 0) {
    return NULL;
  }

  return vec->items[vec->lastItem];
}

void stackvec_clear(StackVec* vec) {
  for(uint32_t idx = 0; idx < vec->lastItem; idx++) {
    vec->items[idx] = NULL;
  }

  vec->lastItem = -1;
}

bool stackvec_isEmpty(StackVec* vec) {
  return vec->lastItem < 0;
}