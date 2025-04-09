#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
    Chunk chunk;
    initChunk(&chunk);

    for (int i = 0; i <= 256; ++i) {
        writeConstant(&chunk, i / 100.0, 123);
    }
    writeChunk(&chunk, OP_RETURN, 124);

    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}
