#ifndef clox_line_h
#define clox_line_h

typedef struct {
    int line;
    int length;
} LineEntry;

typedef struct {
    int capacity;
    int count;
    LineEntry* entry;
} LineArray;

void initLineArray(LineArray* array);
void addLineArray(LineArray* array, int line);
void freeLineArray(LineArray* array);

#endif
