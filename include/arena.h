#ifndef ARENA_H
#define ARENA_H
#include <types.h>

typedef struct Arena
{
    u8* begin;
    u8* current;
    size_t size;
    char* name;
} Arena;

#define ARENA_END(arena) (((Arena*)arena)->begin + ((Arena*)arena)->size)

// Allocate space in the arena and optionally clear it.
void* ArenaAlloc(Arena* arena, size_t size, bool clear);
// Free up all space in the arena.
void ArenaFree(Arena* arena);

#endif /* ARENA_H */