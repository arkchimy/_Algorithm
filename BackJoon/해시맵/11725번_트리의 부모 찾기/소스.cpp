#include <iostream>
#include <vector>
using namespace std;

int pNode[100001];
vector<vector<int>> graph;
void DFS(int n)
{
 
    for(int i=0; i < graph[n].size(); i++)
    {
        if (pNode[graph[n][i]] != false)
            continue;
        pNode[graph[n][i]] = n;
        DFS(graph[n][i]);
    }
}

int main()
{
    int n;
    cin >> n;
    graph.resize(n + 1);
    int a, b;
   
    for (int i =0; i < n - 1;i ++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    DFS(1);
    for (int i = 2; i <= n; i++)
    {
        cout << pNode[i] << "\n";
    }
 }