#include <arena.h>
#include <os.h>
#include <igstdlib.h>

void* ArenaAlloc(Arena* arena, size_t size, bool clear) {
    if ((arena->current + size) > ARENA_END(arena)) {
        OS_PANIC_F("Arena '%s' out of memory.\n", arena->name);
        return NULL;
    }

    u8* ptr = arena->current;

    arena->current += size;

    if (clear) {
        memset(ptr, 0, arena->current - ptr);
    }

    return (void*)ptr;
}

void ArenaFree(Arena* arena) {
    arena->current = arena->begin;
}