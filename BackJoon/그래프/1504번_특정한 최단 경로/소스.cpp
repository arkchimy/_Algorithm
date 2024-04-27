#include<iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<pair<int,int>> graph[800];
int target[2];
long long sum;
long long result[2] = {INT_MAX, INT_MAX};

void sol(int current )
{
    if (current == target[0])
    {
        result[0] = min(result[0], sum);
        return;
    }
    if (current == target[1])
    {
        result[1] = min(result[1], sum);
        return;
    }
    for (int i = 0; i < graph[current].size() ;  i++)
    {
        sum += graph[current][i].second;
        sol(graph[current][i].first);
        sum -= graph[current][i].second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    int a, b, c;

    while (m--)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    
    cin >> target[0] >> target[1];

    sol(1);
    
}