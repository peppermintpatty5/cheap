# cheap

Array-based binary min-heap in C

## Summary

A min-[heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) is a data structure in which every parent node compares less than its children. Therefore, the root node contains the smallest element in heap, which can be accessed in `O(1)` time. The time complexities for adding and removing elements are both `O(log(n))`.

The function prototypes i this library were borrowed from Java's [PriorityQueue](https://docs.oracle.com/javase/10/docs/api/java/util/PriorityQueue.html) method summary page.

## Usage

The program in `main.c` demonstrates how to use this library. Before a heap is used, it must be correctly initialized. A macro is provided in `heap.h` for precisely this purpose:

```c
struct heap h = HEAP(char const *, strptrcmp); /* expands to */
struct heap h = { NULL, strptrcmp, 0, 0, sizeof(char const *) };
```

Notice the resemblance to Java's syntax:
```java
var pq = new PriorityQueue<String>(String.CASE_INSENSITIVE_ORDER);
```

This heap uses `memcpy()` to swap elements as needed. Therefore, to store large structures, it may be better to externally allocate storage and then use the heap to store their pointers. That's how Java does things anyways.

Lastly, this library is compliant with the ANSI C (C89) specification.
