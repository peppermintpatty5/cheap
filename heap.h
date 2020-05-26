#ifndef _HEAP_H
#define _HEAP_H

#include <stddef.h>

#define HEAP(t, f)               \
    {                            \
        NULL, f, 0, 0, sizeof(t) \
    }

/**
 * A function which imposes a total-order relation on any non-null elements.
 */
typedef int (*comparator)(void const *, void const *);

/**
 * Array-based representation of a binary min-heap.
 */
struct heap
{
    void *data;     /* data pointer */
    comparator cmp; /* comparator function */
    size_t size;    /* number of elements */
    size_t cap;     /* storage capacity */
    size_t es;      /* element size */
};

/**
 * Removes all of the elements from the heap.
 */
void h_clear(struct heap *h);

/**
 * Returns non-zero if the heap contains the specified element.
 */
int h_contains(struct heap *h, void const *e);

/**
 * Inserts the specified element into the heap.
 */
int h_offer(struct heap *h, void const *e);

/**
 * Retrieves, but does not remove, the head of the heap. The element is copied
 * to the specified writeback address.
 */
int h_peek(struct heap *h, void *w);

/**
 * Retrieves and removes the head of the heap. The element is copied to the
 * specified writeback address.
 */
int h_poll(struct heap *h, void *w);

#endif
