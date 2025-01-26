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

char* strtok(char* restrict str, const char* restrict set) {
    static size_t pos = 0, oldpos = 0, strlen = 0;
    static char* token = NULL;

    oldpos = pos;

    if (str != NULL) {
        pos = 0, oldpos = 0, strlen = 0;
        token = str;
        while (*str++) strlen++;
    }

    for (size_t i = oldpos; token[i] != '\0'; ++i)
        for (size_t j = 0; set[j] != '\0'; ++j)
            if (token[i] == set[j]) token[i] = '\0';

    for (; token[oldpos] == '\0'; ++oldpos)
        if (strlen + 1 == oldpos) return NULL;

    pos = oldpos;
    for (; token[pos] != '\0'; ++pos);
    pos += 1;

    return token + oldpos;
}
