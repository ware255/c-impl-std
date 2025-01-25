#include "stddef.h"
#include "stdlib.h"

int abs(int n) { return n < 0 ? -n : n; }

long int labs(long int n) { return n < 0 ? -n : n; }

long long int llabs(long long int n) { return n < 0 ? -n : n; }

int atoi(const char* str) {
    int n = 0, neg = 0;
    size_t i = 0;
    while (str[i] == 0x20 || str[i] == 0x09)
        i++;

    if (str[i] == 0x2D) {
        neg = 1;
        i++;
    }
    else if (str[i] == 0x2B)
        i++;

    while (0x30 <= str[i] && str[i] <= 0x39) {
        n = str[i] - 0x30 + n * 10;
        i++;
    }

    return neg ? -n : n;
}

void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)) {
    unsigned char* Base = base;
    for (size_t i = 0; i < nmemb - 1; ++i) {
        for (size_t j = 0; j < nmemb - i - 1; ++j) {
            if (compar(Base + j * size, Base + (j + 1) * size) > 0) {
                for (size_t k = 0; k < size; ++k) {
                    unsigned char temp = Base[j * size + k];
                    Base[j * size + k] = Base[(j + 1) * size + k];
                    Base[(j + 1) * size + k] = temp;
                }
            }
        }
    }
}
