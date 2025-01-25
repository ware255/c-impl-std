#include "stdlib.h"

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

char* strcpy(char* restrict s1, const char* restrict s2) {
    size_t i = 0;
    while (s2[i]) s1[i] = s2[i], i++;
    s1[i] = s2[i];
    return s1;
}

void* memcpy(void* restrict s1, const void* restrict s2, size_t size) {
    char* s1_ = s1;
    const char* s2_ = s2;
    for (size_t i = 0; i < size; ++i)
        s1_[i] = s2_[i];
    return s1;
}

