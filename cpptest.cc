#include <vector>
#include <stdio.h>

#define N 1000000

using namespace std;

int main()
{
    vector<int> v1;
    vector<char> v2;
    vector<unsigned long long> v3;
    vector<bool> v4;
    
    printf("v1...\n");
    for (int i = 0; i < N; ++i)
        v1.push_back(i*3);
    v1.clear();
    
    printf("\nv2...\n");
    for (int i = 0; i < N; ++i)
        v2.push_back(static_cast<char>(i % 65));
    v2.clear();
    
    printf("\nv3...\n");
    for (int i = 0; i < N; ++i)
        v3.push_back((unsigned long long)i*3000);
    v3.clear();
    
    printf("\nv4...\n");
    for (int i = 0; i < N; ++i)
        v4.push_back(!(i % 2));
    v4.clear();
        
    //for (int i = 0; i < 1000000; ++i)
    //    cout << v[i] << " ";
        
    //v.clear();
        
    //cout << endl;
}
