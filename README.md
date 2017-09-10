# malloc
An implementation of the C dynamic memory allocation functions malloc, free, calloc, and realloc.

The memory overhead for block metadata is larger than the standard implementation which is most noticeable when doing a lot of small allocations.
The heap size is managed via the glibc sbrk() function. Allocation requests >= 256kB are allocated via mmap instead of growing the heap.
Thread safety is guaranteed via a pthread mutex.
Beware though, errors will not result in a nice exception like bad_alloc.

A couple test programs along with a makefile are included.
