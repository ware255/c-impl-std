#include "string.h"

void* memchr(const void* s, int c, size_t n) {
    const unsigned char* s_ = s;
    while (n--)
        if (*s_ == c)
            return (unsigned char*)s_;
        else
            s_ += 1;
    return NULL;
}

int memcmp(const void* s1, const void* s2, size_t size) {
    const unsigned char* s1_ = s1;
    const unsigned char* s2_ = s2;
    while (size--)
        if (*s1_ != *s2_) {
            if (*s1_ > *s2_) return 1;
            return -1;
        }
        else
            s1_++, s2_++;
    return 0;
}

void* memcpy(void* restrict s1, const void* restrict s2, size_t size) {
    char* s1_ = s1;
    const char* s2_ = s2;
    while (size--) *s1_++ = *s2_++;
    return s1;
}

void* memmove(void* s1, const void* s2, size_t size) {
    char* s1_ = s1;
    const char* s2_ = s2;
    s1_ += size, s2_ += size;
    while (size--) *--s1_ = *--s2_;
    return s1;
}

void* memset(void* s, int c, size_t n) {
    unsigned char* s_ = s;
    while (n--) *s_++ = c;
    return s_;
}

char* strcat(char* restrict s1, const char* restrict s2) {
    size_t s1Len = 0, s2Len = 0;
    for (; s1[s1Len] != '\0'; ++s1Len);
    for (; s2[s2Len] != '\0'; ++s2Len);
    for (size_t i = s1Len; i < s1Len + s2Len + 1; ++i)
        s1[i] = s2[i - s1Len];
    return s1;
}

char* strchr(const char* s, int c) {
    while (*s++)
        if (*s == c)
            return (char*)s;
    return NULL;
}

int strcmp(const char* s1, const char* s2) {
    for (size_t i = 0; s1[i] != '\0' || s2[i] != '\0'; ++i)
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i]) return 1;
            return -1;
        }
    return 0;
}

char* strcpy(char* restrict s1, const char* restrict s2) {
    char* s1_ = s1;
    while (*s1_++) *s1_ = *s2++;
    return s1;
}

size_t strcspn(const char* s1, const char* s2) {
    size_t count = 0;
    for (size_t i = 0; s1[i] != '\0'; ++i, ++count)
        for (size_t j = 0; s2[j] != '\0'; ++j)
            if (s1[i + j] == s2[j])
                return count;
    return count;
}

size_t strlen(const char* str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

char* strncat(char* restrict s1, const char* restrict s2, size_t n) {
    size_t s1Len = 0, s2Len = 0;
    for (; s1[s1Len] != '\0'; ++s1Len);
    for (; s2[s2Len] != '\0'; ++s2Len);
    if (n < s2Len) s2Len = n - 1;
    for (size_t i = s1Len; i < s1Len + s2Len + 1; ++i)
        s1[i] = s2[i - s1Len];
    s1[s1Len + s2Len + 1] = '\0';
    return s1;
}

int strncmp(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n || s1[i] != '\0' || s2[i] != '\0'; ++i)
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i]) return 1;
            return -1;
        }
    return 0;
}

char* strncpy(char* s1, const char* s2, size_t n) {
    char* s1_ = s1;
    while (n--) *s1_++ = *s2++;
    return s1;
}

char* strrchr(const char* s, int c) {
    size_t len = 0;
    for (; s[len] != '\0'; ++len);
    for (; s[len] != c; --len);
    return (char*)s + len;
}

size_t strspn(const char* s1, const char* s2) {
    size_t count = 0, Len = 0;
    for (; s2[Len] != '\0'; ++Len);
    for (size_t i = 0; s1[i] != '\0'; ++i)
        for (size_t j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                count++;
                break;
            }
            if (s1[i] != s2[j] && j == Len - 1)
                return count;
        }
    return count;
}

char* strstr(const char* s1, const char* s2) {
    for (size_t i = 0; s1[i] != '\0'; ++i)
        for (size_t j = 0; s2[j] != '\0'; ++j)
            if (s1[i + j] == s2[j])
                return (char*)s1 + i;
    return NULL;
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
