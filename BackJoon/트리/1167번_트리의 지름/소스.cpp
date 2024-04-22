#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

vector<pair<int, int>> tree[MAX]; // 인접 리스트로 트리 구현
bool visited[MAX];
int maxDistance = 0;
int farthestNode = 0;

void dfs(int node, int distance)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (distance > maxDistance)
    {
        maxDistance = distance;
        farthestNode = node;
    }

    for (auto &edge : tree[node])
    {
        int nextNode = edge.first;
        int weight = edge.second;

        if (!visited[nextNode])
        {
            dfs(nextNode, distance + weight);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V; // 노드의 개수

    // 트리 정보 입력 받기
    for (int i = 0; i < V; ++i)
    {
        int node;
        cin >> node;

        while (true)
        {
            int neighbor, weight;
            cin >> neighbor;
            if (neighbor == -1)
                break;
            cin >> weight;
            tree[node].push_back({neighbor, weight});
            tree[neighbor].push_back({node, weight}); // 무방향 그래프이므로 양방향 연결
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(3, 0);

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(farthestNode, 0);

    cout << maxDistance << '\n';

    return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <queue>
//#include <vector>
//#define INF 10001
//using namespace std;
//
//vector<vector<pair<int, int>>> graph;
//
//vector<int> dijkstra(int start, int n)
//{
//    vector<int> dist(n + 1, INF);
//    dist[start] = 0;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push({0, start});
//
//    while (!pq.empty())
//    {
//        int curr = pq.top().second;
//        int curr_dist = pq.top().first;
//        pq.pop();
//
//        if (curr_dist > dist[curr])
//            continue;
//
//        for (auto &edge : graph[curr])
//        {
//            int next = edge.first;
//            int weight = edge.second;
//
//            if (dist[curr] + weight < dist[next])
//            {
//                dist[next] = dist[curr] + weight;
//                pq.push({dist[next], next});
//            }
//        }
//    }
//
//    return dist;
//}
//
//int main()
//{
//
//    int n;
//    scanf("%d", &n);
//
//    // 그래프 초기화 및 입력
//    graph.resize(n + 1);
//
//    for (int i = 1; i <= n; i++)
//    {
//        int start;
//        scanf("%d", &start);
//        while (true)
//        {
//            int target, distance;
//            scanf("%d", &target);
//            if (target == -1)
//                break;
//            scanf("%d", &distance);
//            graph[start].push_back({target, distance});
//        }
//    }
//
//    int result = 0;
//
//    for (int i = 1; i <= n; i++)
//    {
//        vector<int> dist = dijkstra(i, n);
//        for (int j = 1; j <= n; j++)
//        {
//            if (dist[j] != INF && dist[j] > result)
//                result = dist[j];
//        }
//    }
//
//    cout << result << "\n";
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define INF 10001
// using namespace std;
//
// vector<vector<int>> graph;
//
// void dijk()
//{
//    for (int start = 1; start < graph.size(); start++)
//    {
//        for (int target = 1; target < graph.size(); target++)
//        {
//            if (start == target)
//                continue;
//            if (graph[start][target] != INF)
//            {
//                for (int i = 1; i < graph.size(); i++)
//                {
//                    if (i == target || graph[target][i] == INF)
//                        continue;
//                    int total = graph[start][target] + graph[target][i];
//                    graph[start][i] = min(graph[start][i], total);
//                }
//            }
//        }
//    }
//}
// int main()
//{
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    graph.resize(n + 1, vector<int>(n + 1, INF));
//    for (int i =1; i <= n; i++)
//    {
//        graph[i][i] = 0;
//    }
//    int start, target,distance;
//    // init;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> start;
//        while (1)
//        {
//            cin >> target;
//            if (target == -1)
//                break;
//            cin >> distance;
//            graph[start][target] = distance;
//        }
//    }
//    dijk();
//    int result =0 ;
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j =1; j <=n ; j++)
//        {
//            if(graph[i][j] != INF)
//                result = max(result, graph[i][j]);
//        }
//    }
//
//    cout << result;
//}