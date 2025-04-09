#include "line.h"
#include "memory.h"

void initLineArray(LineArray* array) {
    array->capacity = 0;
    array->count = 0;
    array->entry = NULL;
}

void addLineArray(LineArray* array, int line) {
    if (array->count > 0 && array->entry[array->count - 1].line == line) {
        array->entry[array->count - 1].length++;
        return;
    }

    if (array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->entry = GROW_ARRAY(LineEntry, array->entry, oldCapacity, array->capacity);
    }
    array->entry[array->count].line = line;
    array->entry[array->count].length = 1;
    array->count++;
}

void freeLineArray(LineArray* array) {
    FREE_ARRAY(LineEntry, array->entry, array->capacity);
    initLineArray(array);
}
