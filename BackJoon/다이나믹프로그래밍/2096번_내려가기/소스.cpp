#include <algorithm>
#include <climits> // INT_MAX, INT_MIN 사용을 위해 추가
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxDP[3] = {0, 0, 0};
    int minDP[3] = {0, 0, 0};

    cin >> maxDP[0] >> maxDP[1] >> maxDP[2];
    minDP[0] = maxDP[0];
    minDP[1] = maxDP[1];
    minDP[2] = maxDP[2];

    for (int i = 1; i < n; i++)
    {
        int input[3];
        cin >> input[0] >> input[1] >> input[2];

        int temp_0 = maxDP[0];
        int temp_2 = maxDP[2];
        maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
        maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
        maxDP[1] = max(max(temp_0, maxDP[1]), temp_2) + input[1];

      
        temp_0 = minDP[0];
        temp_2 = minDP[2];
        minDP[0] = min(minDP[0], minDP[1]) + input[0];
        minDP[2] = min(minDP[1], minDP[2]) + input[2];
        minDP[1] = min(min(temp_0, minDP[1]), temp_2) + input[1];
    }


    int maxResult = max(max(maxDP[0], maxDP[1]), maxDP[2]);
    int minResult = min(min(minDP[0], minDP[1]), minDP[2]);

    cout << maxResult << " " << minResult << "\n";

    return 0;
}
//#include <iostream>
//#include <vector>
//#include <limits.h>
//using namespace std;
//
//
//vector<vector<int>> graph;
//int sum;
//int result[2];
//int cnt;
//
//void sol(int idx)
//{
//    if (idx == graph[0].size())
//    {
//        result[0] = max(sum, result[0]);
//        result[1] = min(sum, result[1]);
//        return;
//    }
//    if (0 <= cnt  && cnt  < graph.size())
//    {
//        sum += graph[idx][cnt];
//        sol(idx + 1);
//        sum -= graph[idx][cnt];
//    }
//
//    if (0 <= cnt - 1 && cnt - 1 < graph.size())
//    {
//        sum += graph[idx][cnt - 1];
//        sol(idx + 1);
//        sum -= graph[idx][cnt - 1];
//    }
//    if (0 <= cnt + 1 && cnt + 1 < graph.size())
//    {
//        sum += graph[idx][cnt + 1];
//        sol(idx + 1);
//        sum -= graph[idx][cnt + 1];
//    }
//}
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    result[1] = INT_MAX;
//    int n;
//    cin >> n;
//    graph.resize(n);
//    for (int i = 0; i < n; i++)
//    {
//        graph[i].resize(n);
//        for (int j = 0; j < n; j++)
//        {
//            cin >> graph[i][j];
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        sum = graph[0][i];
//        cnt = i;
//        sol(1);
//    }
//    cout << result[0] << " " << result[1];
//}