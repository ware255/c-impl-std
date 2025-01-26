#include "ctype.h"

int isalnum(int c) {
    return (
        (0x30 <= c && c <= 0x39) ||
        (0x41 <= c && c <= 0x5A) ||
        (0x61 <= c && c <= 0x7A)
    ) ? 1 : 0;
}

int isalpha(int c) {
    return (
        (0x41 <= c && c <= 0x5A) ||
        (0x61 <= c && c <= 0x7A)
    ) ? 1 : 0;
}

int isblank(int c) {
    return (c == 0x09 || c == 0x20) ? 1 : 0;
}

int iscntrl(int c) {
    return (
        (0x00 <= c && c <= 0x19) ||
        (0x1A <= c && c <= 0x1F) ||
        (c == 0x7F)
    ) ? 1 : 0;
}

int isdigit(int c) {
    return (0x30 <= c && c <= 0x39) ? 1 : 0;
}

int isgraph(int c) {
    return (0x21 <= c && c <= 0x7E) ? 1 : 0;
}

int islower(int c) {
    return (0x61 <= c && c <= 0x7A) ? 1 : 0;
}

int isprint(int c) {
    return (0x20 <= c && c <= 0x7E) ? 1 : 0;
}

int ispunct(int c) {
    return (
        (0x21 <= c && c <= 0x2F) ||
        (0x3A <= c && c <= 0x40) ||
        (0x5B <= c && c <= 0x60) ||
        (0x7B <= c && c <= 0x7E)
    ) ? 1 : 0;
}

int isspace(int c) {
    return (
        (0x09 <= c && c <= 0x0D) ||
        (c == 0x20)
    ) ? 1 : 0;
}

int isupper(int c) {
    return (0x41 <= c && c <= 0x5A) ? 1 : 0;
}

int isxdigit(int c) {
    return (
        (0x30 <= c && c <= 0x39) ||
        (0x41 <= c && c <= 0x46) ||
        (0x61 <= c && c <= 0x66)
    ) ? 1 : 0;
}

int tolower(int c) {
    if (0x41 <= c && c <= 0x5A)
        return c + 0x20;
    return c;
}

int toupper(int c) {
    if (0x61 <= c && c <= 0x7A)
        return c - 0x20;
    return c;
}
