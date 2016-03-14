#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define N 10
//#define N 1
#define BYTES 256 * 1024;

int count = 0;

int main()
{
    srand((unsigned)time(NULL));
    FILE *file = fopen("test.dat", "w");
    
    size_t bytes;
    //for (bytes = 1; bytes < 256 * 1024; ++bytes)
    for (bytes = 0; bytes <= 768 * 1024; bytes += 32)
    {
        clock_t start = clock();
        
        size_t i;
        void *stuff[N];
        for (i = 0; i < N; ++i)
        {
            size_t n_bytes = (bytes ? rand() % bytes : 0);
            stuff[i] = malloc(n_bytes);
            memset(stuff[i], 0, n_bytes);
        }
        
        for (i = 0; i < N - 1; ++i)
        {
            free(stuff[i]);
        }
        
        clock_t end = clock();
        float seconds = (float)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d %f\n", (int)bytes, seconds);
    }
    
    fclose(file);
    
    return 0;
}
