#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


vector<vector<int>> graph;
int sum;
int result[2];
int cnt;

void sol(int idx)
{
    if (idx == graph[0].size())
    {
        result[0] = max(sum, result[0]);
        result[1] = min(sum, result[1]);
        return;
    }
    if (0 <= cnt  && cnt  < graph.size())
    {
        sum += graph[idx][cnt];
        sol(idx + 1);
        sum -= graph[idx][cnt];
    }

    if (0 <= cnt - 1 && cnt - 1 < graph.size())
    {
        sum += graph[idx][cnt - 1];
        sol(idx + 1);
        sum -= graph[idx][cnt - 1];
    }
    if (0 <= cnt + 1 && cnt + 1 < graph.size())
    {
        sum += graph[idx][cnt + 1];
        sol(idx + 1);
        sum -= graph[idx][cnt + 1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    result[1] = INT_MAX;
    int n;
    cin >> n;
    graph.resize(n);
    for (int i = 0; i < n; i++)
    {
        graph[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum = graph[0][i];
        cnt = i;
        sol(1);
    }
    cout << result[0] << " " << result[1];
}