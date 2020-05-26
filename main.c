#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap.h"

#define N 50

static int intcmp(void const *va, void const *vb)
{
    return *(int *)va - *(int *)vb;
}

static void h_print(struct heap *h)
{
    size_t n;

    for (n = 0; n < h->size; n++)
        printf("%i ", ((int *)h->data)[n]);
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    int i;
    int a[N];
    struct heap h = HEAP(int, intcmp);

    srand(time(NULL));
    for (i = 0; i < N; i++)
        a[i] = rand() % 100;

    for (i = 0; i < N; i++)
    {
        h_offer(&h, &a[i]);
        printf("offer %2i;\t", a[i]);
        h_print(&h);
    }

    while (h.size)
    {
        h_poll(&h, &i);
        printf("poll %2i;\t", i);
        h_print(&h);
    }

    (void)argc, (void)argv; /* suppress -Wextra */
    return EXIT_SUCCESS;
}
