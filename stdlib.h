#ifndef _STDLIB_H_
#define _STDLIB_H_

int abs(int n);
int atoi(const char* str);
void* bsearch(const void* key, void* base, size_t count, size_t size, int (*compar)(const void* key, const void* value));
void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));

#endif // _STDLIB_H_
