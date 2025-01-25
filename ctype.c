#include "ctype.h"

int isupper(int c) {
    return (0x41 <= c && c <= 0x5A) ? 1 : 0;
}

int islower(int c) {
    return (0x61 <= c && c <= 0x7A) ? 1 : 0;
}
