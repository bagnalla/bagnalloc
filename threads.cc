#include <iostream>
#include <vector>
#include <omp.h>
#include <string.h>

using namespace std;

#define N 1000
//#define N 1
#define k 10000;

int main()
{
    #pragma omp parallel for
    for (size_t j = 0; j < 100; ++j)
    {
        //printf("%d\n", j);
        
        void *stuff[N];
        for (size_t i = 0; i < N; ++i)
        {
            size_t n = rand() % k;
            //size_t n = 1;
            //size_t n = k;
            stuff[i] = malloc(n);
            memset(stuff[i], 69, n);
        }
        
        for (size_t i = 0; i < N; ++i)
            free(stuff[i]);
        
        for (size_t i = 0; i < N; ++i)
        {
            size_t n = rand() % k;
            stuff[i] = calloc(n, 4);
        }
        
        for (size_t i = 0; i < N; ++i)
        {
            size_t n = rand() % k;
            stuff[i] = realloc(stuff[i], n);
        }
        
        for (size_t i = 0; i < N; ++i)
            free(stuff[i]);
    }
    
    void *stuff[N];
    for (size_t i = 0; i < N; ++i)
    {
        size_t n = rand() % k;
        //size_t n = 1;
        //size_t n = k;
        stuff[i] = malloc(n);
        memset(stuff[i], 69, n);
    }
    
    return 0;
}
