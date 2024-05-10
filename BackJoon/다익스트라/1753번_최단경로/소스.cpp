#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

#define INF INT_MAX
using namespace std;

vector<vector<pair<int, int>>> graph;

vector<int> answer;

void dist(int current)
{
    
    answer[current] = 0;

    priority_queue<pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0, current});

    while (!pq.empty())
    {
        auto [cost,v] = pq.top();
        pq.pop();

        for (auto [node, weight] : graph[v])
        {
            if (answer[node] > weight + cost)
            {
                answer[node] = weight + cost;
                pq.push({answer[node], node});
            }
        }
        
    }
}
int main()
{
    int n, m;
    int start;
    cin >> n >> m;
    cin >> start;

    graph.resize(n + 1);
    answer.resize(n + 1,INF);

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);

    }
    dist(start);
    for (int i = 1; i <= n; i++)
    {
        if (answer[i] == INF)
            cout << "INF\n";
        else
            cout << answer[i] << "\n";
    }
}