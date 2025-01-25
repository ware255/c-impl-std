#ifndef _STRING_H_
#define _STRING_H_

//typedef unsigned long long size_t;
typedef unsigned int size_t;

size_t strlen(const char* str);
char* strcpy(char* restrict s1, const char* restrict s2);
void* memcpy(void* restrict s1, const void* restrict s2, size_t size);

#endif // _STDLIB_H_
