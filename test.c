#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define N 1000
//#define N 1
#define k 10000;

extern void* my_malloc(size_t size);
extern void my_free(void *ptr);
extern void safe_print(const char *s, size_t size);

int count = 0;

int main()
{
	//time_t t;
	//srand((unsigned) time(&t));
	
	size_t i, j;
	
	//for (i = 0; i < N; ++i)
	//{
		//size_t n = rand() % k;
		////size_t n = 1000;
		//int *nums = malloc(n * sizeof(int));
		//for (j = 0; j < n; ++j)
		//{
			//nums[j] = j;
		//}
		
		//free(nums);
		
		//count++;
	//}
	
	for (j = 0; j < 1000; ++j)
	{
		void *stuff[N];
		for (i = 0; i < N; ++i)
		{
			size_t n = rand() % k;
			//size_t n = 1;
			//size_t n = k;
			stuff[i] = malloc(n);
			memset(stuff[i], 69, n);
		}
		
		for (i = 0; i < N; ++i)
		{
			free(stuff[i]);
		}
	}
	
	void *stuff[N];
	for (i = 0; i < N; ++i)
	{
		size_t n = rand() % k;
		//size_t n = 1;
		//size_t n = k;
		stuff[i] = malloc(n);
		memset(stuff[i], 69, n);
	}
	
	//for (i = 0; i < 50000000; ++i)
	//{
		//int *num = my_malloc(sizeof(int));
		//*num = 0;
	//}
	
	//while (1);
	
	return 0;
}
