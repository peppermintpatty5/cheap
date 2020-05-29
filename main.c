#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "heap.h"

/**
 * The built-in strcmp() function compares strings, this function compares
 * pointers to strings.
 */
static int strptrcmp(void const *va, void const *vb)
{
    typedef char const *T; /* make the Java programmers feel at home */
    T a = *(T *)va, b = *(T *)vb;

    return strcmp(a, b);
}

/**
 * A simple program that demonstrates heap sort.
 */
int main(int argc, char const *argv[])
{
    int i;
    char const *str;
    struct heap h = HEAP(char const *, strptrcmp);

    if (argc > 1)
    {
        for (i = 1; i < argc; i++)
            h_offer(&h, &argv[i]);

        while (h_poll(&h, &str))
            printf("%s ", str);
    }
    else
        printf("Run this program with some arguments to see heap sort!");
    putchar('\n');

    return EXIT_SUCCESS;
}
