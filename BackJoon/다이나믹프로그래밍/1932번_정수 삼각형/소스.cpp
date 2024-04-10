#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m = 0;
    cin >> n;

    graph.resize(n + 1);
    for (int i =1; i <= n; i++)
    {
        m++;
        graph[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }

    for (int i = n; i >= 1; i--)
    {
        for (int k = 0; k < graph[i-1].size(); k++)
        {
            int a = graph[i][k] + graph[i - 1][k];
            int b = graph[i][k + 1] + graph[i - 1][k];
            graph[i - 1][k] = max(a,b);
        }
    }
    cout << graph[1][0];
}

//#include <iostream>  //DFS 시간 초과
//#include <vector>
//
//
//using namespace std;
//
//int dx[] = {1, 1};
//int dy[] = {0,1};
//vector<vector<int>> graph;
//
//int result;
//int n;
//void sol(pair<int,int> current,int depth,int& sum)
//{
//    if (depth == n)
//    {
//        result = max(result, sum);
//        return;
//    }
//    for (int i =0; i < 2 ; i++)
//    {
//        int rx = current.first + dx[i];
//        int ry = current.second + dy[i];
//        sum += graph[rx][ry];
//        sol({rx,ry} ,depth + 1, sum);
//        sum -= graph[rx][ry];
//    }
//
//}
//
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n ;
//    graph.resize(n);
//    int m = 0;
//    for (int i =0; i < n; i++)
//    {
//        m++;
//        graph[i].resize(m);
//        for (int j = 0; j < graph[i].size(); j++)
//            cin >> graph[i][j];
//    }
//
//    sol({0,0} ,1, graph[0][0]);
//
//    cout << result;
//    
//}