#ifndef STACKVEC_STACKVEC_H
#define STACKVEC_STACKVEC_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct StackVec {
    void** items;
    int32_t lastItem;
    size_t max;
    size_t item_size;
} StackVec;

StackVec stackvec_create(size_t max, size_t item_size);
bool stackvec_pushElement(StackVec* vec, void* item);
bool stackvec_removeElement(StackVec* vec, size_t index);
void* stackvec_front(StackVec* vec);
void* stackvec_back(StackVec* vec);
void stackvec_clear(StackVec* vec);
bool stackvec_isEmpty(StackVec* vec);

#endif //STACKVEC_STACKVEC_H
