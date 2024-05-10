#include <functional>
#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

const long long INF = INT_MAX;
vector<pair<int, int>> graph[801];
long long dist[801];

void dijkstra(int start)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + 801, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] < cost)
            continue;

        for (auto &[v, weight] : graph[u])
        {
            long long next_dist = cost + weight;
            if (dist[v] > next_dist)
            {
                dist[v] = next_dist;
                pq.push({next_dist, v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int v1, v2;
    cin >> v1 >> v2;

    long long res1 = 0, res2 = 0;
    // 1 -> v1 -> v2 -> N °æ·Î
    dijkstra(1);
    long long d1v1 = dist[v1], d1v2 = dist[v2];
    dijkstra(v1);
    long long dv1v2 = dist[v2], dv1N = dist[n];
    dijkstra(v2);
    long long dv2N = dist[n];

    res1 = d1v1 + dv1v2 + dv2N; // 1 -> v1 -> v2 -> N
    res2 = d1v2 + dv1v2 + dv1N; // 1 -> v2 -> v1 -> N

    long long answer = min(res1, res2);
    if (answer >= INF || answer < 0) 
        cout << "-1\n";
    else
        cout << answer << '\n';

    return 0;
}