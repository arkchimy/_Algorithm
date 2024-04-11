#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> m;
    
    int n;
    scanf("%d",&n);

    int a, b;

    for (int i =0; i < n-1 ; i++)
    {
        scanf("%d %d", &a,&b);
        if (m[a] == 0)
            m[a] = b;
        if (m[b] == 0)
            m[b] = a;
    }
    int parent = 1;
    for (int i = 1; i < n; i++)
    {
        int child = m[parent];
        m[child] = parent;
        parent = child;
    }

    for (int i = 2; i <= n; i++)
    {
        printf("%d \n", m[i]);
    }

}