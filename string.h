#ifndef _STRING_H_
#define _STRING_H_

#define NULL ((void *)0)

//typedef unsigned long long size_t;
typedef unsigned int size_t;

void* memchr(const void* s, int c, size_t n);
int memcmp(const void* s1, const void* s2, size_t size);
void* memcpy(void* restrict s1, const void* restrict s2, size_t size);
void* memmove(void* s1, const void* s2, size_t size);
void* memset(void* s, int c, size_t n);
char* strcat(char* restrict s1, const char* restrict s2);
char* strchr(const char* s, int c);
int strcmp(const char* s1, const char* s2);
char* strcpy(char* restrict s1, const char* restrict s2);
size_t strcspn(const char* s1, const char* s2);
size_t strlen(const char* str);
char* strncat(char* restrict s1, const char* restrict s2, size_t n);
int strncmp(const char* s1, const char* s2, size_t n);
char* strncpy(char* s1, const char* s2, size_t n);
char* strrchr(const char* s, int c);
size_t strspn(const char* s1, const char* s2);
char* strstr(const char* s1, const char* s2);
char* strtok(char* restrict str, const char* restrict set);

#endif // _STRING_H_
