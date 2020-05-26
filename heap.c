#include <stdlib.h>
#include <string.h>

#include "heap.h"

/**
 * Macro for accessing the address of the nth element of the heap.
 */
#define H(n) ((void *)((char *)h->data + h->es * (n)))

/**
 * Attempts to double the capacity of the heap. If the capacity is initally 0,
 * then the capacity will become 1.
 */
static int h_expand(struct heap *h)
{
    size_t n = h->cap ? h->cap * 2 : 1;
    void *r = realloc(h->data, h->es * (n + 1)); /* +1 for swap */

    if (r)
        h->data = r, h->cap = n;

    return !!r;
}

/**
 * Swaps two elements in the heap.
 */
static void h_swap(struct heap *h, void *a, void *b)
{
    void *t = H(h->cap);
    memcpy(t, a, h->es);
    memcpy(a, b, h->es);
    memcpy(b, t, h->es);
}

void h_clear(struct heap *h)
{
    free(h->data);
    h->data = NULL;
    h->size = 0;
    h->cap = 0;
}

int h_contains(struct heap *h, void const *e)
{
    size_t n;

    for (n = 0; n < h->size; n++)
        if (h->cmp(H(n), e) == 0)
            return 1;

    return 0;
}

int h_offer(struct heap *h, void const *e)
{
    if (h->size < h->cap || h_expand(h))
    {
        size_t n = h->size;
        memcpy(H(n), e, h->es);

        while (n > 0)
        {
            void *child = H(n),
                 *parent = H((n - 1) / 2);

            if (h->cmp(child, parent) < 0)
                h_swap(h, child, parent);
            else
                break;

            n = (n - 1) / 2;
        }

        h->size++;
        return 1;
    }
    else
        return 0;
}

int h_peek(struct heap *h, void *w)
{
    if (h->data)
        memcpy(w, H(0), h->es);

    return !!h->data;
}

int h_poll(struct heap *h, void *w)
{
    if (h->data)
    {
        size_t n = 0;
        memcpy(w, H(0), h->es);
        memcpy(H(0), H(h->size - 1), h->es);

        h->size--;
        while (n < h->size)
        {
            void *parent = H(n),
                 *child1 = n * 2 + 1 < h->size ? H(n * 2 + 1) : NULL,
                 *child2 = n * 2 + 2 < h->size ? H(n * 2 + 2) : NULL,
                 *min = child1 && child2
                            ? (h->cmp(child1, child2) < 0 ? child1 : child2)
                            : child1;

            if (min && h->cmp(min, parent) < 0)
                h_swap(h, min, parent);
            else
                break;

            n = n * 2 + (min == child1 ? 1 : 2);
        }
    }

    return !!h->data;
}
