#include <iostream>
#include <vector>
#include <omp.h>
#include <string.h>
#include <ctime>

using namespace std;

#define N 500
//#define N 1
#define k 512 * 1024;

int main()
{
    srand((unsigned)time(NULL));
    
    // execute 64 times in parallel
    #pragma omp parallel for
    for (size_t j = 0; j < 64; ++j)
    {
        ////////////////////////////////////////////////////////////////
        // STEP 1: MALLOC + FREE
        ////////////////////////////////////////////////////////////////
        
        // random number of pointers. range = [0, 499]
        size_t NN = rand() % N;
        void *stuff1[NN];
        
        // malloc for each pointer
        for (size_t i = 0; i < NN; ++i)
        {
            // random number of bytes. range = [0, 99999]
            size_t n = rand() % k;
            stuff1[i] = malloc(n);
            memset(stuff1[i], 0, n);
        }
        
        // free memory for each pointer except one
        for (size_t i = 0; i < NN ? NN - 1 : 0; ++i)
            free(stuff1[i]);
        
        ////////////////////////////////////////////////////////////////
        // STEP 2: CALLOC + REALLOC + FREE
        ////////////////////////////////////////////////////////////////
        
        // random number of pointers. range = [0, 499]
        NN = rand() % N;
        void *stuff2[NN];
        
        // calloc for each pointer
        for (size_t i = 0; i < NN; ++i)
        {
            // random number of bytes. range = [0, 99999]
            size_t n = rand() % k;
            stuff2[i] = calloc(n, 4);
        }
        
        // realloc for each pointer
        for (size_t i = 0; i < NN; ++i)
        {
            // random number of bytes. range = [0, 99999]
            size_t n = rand() % k;
            stuff2[i] = realloc(stuff2[i], n);
        }
        
        // free memory for each pointer except one
        for (size_t i = 0; i < NN ? NN - 1 : 0; ++i)
            free(stuff2[i]);
    }
    
    // one last round of mallocs for good measure
    void *stuff[N];
    for (size_t i = 0; i < N; ++i)
    {
        size_t n = rand() % k;
        stuff[i] = malloc(n);
        memset(stuff[i], 0, n);
    }
    
    return 0;
}
