# bagnalloc
An alternative implementation of the C dynamic memory allocation functions malloc, free, calloc, and realloc.

All dynamic memory is allocated in heap which is implemented as a doubly-linked list.
They can be used as a general-purpose replacement for the equivalent standard library functions.
This implementation tends to perform better than the standard implementation for medium/large allocations but worse for small allocations.
The memory overhead for block metadata is also larger than the standard implementation which is most noticeable when doing a lot of small allocations.
The heap size is managed via the glibc sbrk() function.
Thread safety is guaranteed via a pthread mutex. (must be compiled with -pthread compiler flag)
