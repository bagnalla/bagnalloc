# bagnalloc
An alternative implementation of the C dynamic memory allocation functions malloc, free, calloc, and realloc.

These functions can be used as a general-purpose replacement for the equivalent standard library functions (or so I think - may be unsafe in some way).
In my testing this implementation seems perform the same or better than the standard implementation except for heavy parallel allocation (less efficient usage of mutex I guess)
The memory overhead for block metadata is also larger than the standard implementation which is most noticeable when doing a lot of small allocations.
The heap size is managed via the glibc sbrk() function. Allocation requests >= 128kB are allocated via mmap instead of growing the heap.
Thread safety is guaranteed via a pthread mutex.
Beware though, errors will not result in a nice exception like bad_alloc.

A couple test programs along with a makefile are included.
