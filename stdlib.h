#ifndef _STDLIB_H_
#define _STDLIB_H_

int abs(int n);
long int labs(long int n);
long long int llabs(long long int n);
int atoi(const char* str);
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));

#endif
