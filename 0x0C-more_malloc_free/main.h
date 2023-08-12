#ifndef MAIN_H
#define MAIN_H

void *malloc_checked(unsigned int b);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void errors(void);
char *string_nconcat(char *s1, char *s2, unsigned int n);
int *array_range(int min, int max);
int _putchar(char c);
int _strlen(char *s);
int is_digit(char *s);




#endif
