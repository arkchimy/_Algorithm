#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>


using namespace std;

int dp[1025][1025];

void sol(pair<int,int> start, pair<int,int> target)
{
    int result = 0;
    for (int i = start.first; i <= target.first; i++)
    {
        result += dp[i][target.second] - dp[i][start.second - 1];
    }
    printf("%d \n", result);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i =1; i <= N;i++)
    {
        int sum = 0;
        int temp;
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &temp);
            sum += temp;
            dp[i][j] = sum;
        }
        
    }
    while (M--)
    {
        pair<int, int> p1,p2;
        scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
        sol(p1, p2);
    }
}