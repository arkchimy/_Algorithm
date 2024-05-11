#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<int> dijk;
vector<vector<int>> graph;


void sol(int start)
{
    dijk[start] = 0;
    priority_queue < pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        for (int n : graph[node])
        {
            if (dijk[n] > cost + 1)
            {
                dijk[n] = cost + 1;
                pq.push({cost + 1, n});
            }
        }
    }

}
int main()
{
    int n, m, target, start;
    cin >> n >> m >> target >> start;

    dijk.resize(n + 1, INT_MAX);
    graph.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;

        graph[a].emplace_back(b);
    }
    sol(start);
    bool bchk = false;
    for (int i = 1; i < dijk.size(); i++)
    {
        if (dijk[i] == target)
        {
            bchk = true;
            cout << i << "\n";
        }
        
    }
    if (!bchk)
        cout << -1;
}