#ifndef IGSTDLIB_H
#define IGSTDLIB_H
#include <types.h>

// Compares the value of `s1` to `s2` without case sensitivity.
extern int strcasecmp(char* __s1, char* __s2);
// Compares the value of `s1` to `s2`.
extern int strcmp(char* __s1, char* __s2);
// Copies `s2` into `s1`.
extern char* strcpy(char* __s1, char* __s2);
// Calculates the length of `s`.
extern size_t strlen(char* __s);
// Copies up to `n` characters of `s2` to `s1`.
extern char* strncpy(char* __s1, char* __s2, size_t n);
// Mutates `s` to contain only upper case characters.
extern char* strupr(char* __s);
// Reverses the order of characters in `s`.
extern char* strrev(char* __s);
// Concatenate the string `src` with the string `dest` and put it in `dest`.
extern char* strcat(char* __dest, char* __src);
// Concatenate `n` characters in the string `src` with the string `dest` and put it in `dest`.
extern char* strncat(char* __dest, char* __src, size_t __n);
// Compare `n` characters between `s1` and `s2`.
extern int strncmp(char* __s1, char* __s2, size_t __n);
// Find the first occourance of the string `needle` in the string `haystack`.
extern char* strstr(char* __haystack, char* __needle);

// Convert a char string to a wchar string
extern void Wcscpy(wchar16* pDest, char* pSource);

// Copy `n` bytes from `src` to `dest`.
extern void* memcpy(void* __dest, void* __src, size_t __n);
// Copy `n` bytes from `src` to `dest`.
extern void* memmove(void* __dest, void* __src, size_t __n);
// Set `n` bytes at `s` to value `c`.
extern void* memset(void* __s, int __c, size_t __n);
// Sums up differences between `n` bytes between `s1` and `s2`.
extern int memcmp(void* __s1, void* __s2, size_t __n);

// Prints a formatted string to the standard output.
extern int printf(char* __format, ...);
// Prints a formatted string using arguments `arg` to the standard output;
extern int vprintf(char* __format, va_list __arg);
// Formats the string `format` and stores it in `s`.
extern int sprintf(char* __s, char* __format, ...);
// Formats the string `format` using arguments `arg` and stores it in `s`.
extern int vsprintf(char* __s, char* __format, va_list __arg);

#endif /* IGSTDLIB_H */