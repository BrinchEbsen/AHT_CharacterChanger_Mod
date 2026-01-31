#ifndef OS_H
#define OS_H

// GameCube/Wii Print Function (printf equivalent)
// Outputs to the console in Dolphin
extern void OSReport(const char* fmt, ...);

// GameCube/Wii Error Alert Function
// Pops up an alert window with a message in Dolphin (if panic handlers are enabled)
extern void OSPanic(const char* file, int line, const char* fmt, ...);

#define OS_PANIC(fmt) OSPanic(__FILE_NAME__, __LINE__, fmt)
#define OS_PANIC_F(fmt, ...) OSPanic(__FILE_NAME__, __LINE__, fmt, __VA_ARGS__)

#endif // OS_H
