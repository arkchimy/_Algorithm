#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

#define SIZE 100001
int dp[SIZE];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(dp, dp + SIZE, INT_MAX);
 
	int start, target;

	cin >> start >> target;

    dp[start] = 0;

    if (start <= target)
    {
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int current : {front + 1, front - 1, front * 2})
            {
                if ( current < 0 || SIZE <= current )
                    continue;
                if (dp[current] != INT_MAX)
                    continue;
                dp[current] = dp[front] + 1;
                if (current == target)
                {
                    cout << dp[target];
                    return 0;
                }
                q.push(current);
            }
        }
    }
    dp[target] = abs(target - start);
	cout << dp[target];
}
 
//int BFS(int start, int target)
//{
//    if (start >= target)
//        return start - target; // target이 start보다 작거나 같은 경우, -1만 계속 사용
//
//    vector<int> visited(100001, -1); // 방문 체크 및 거리 저장
//    queue<int> q;
//
//    // 초기 위치 설정
//    visited[start] = 0;
//    q.push(start);
//
//    while (!q.empty())
//    {
//        int current = q.front();
//        q.pop();
//
//        // 가능한 모든 이동 시도
//        for (int next : {current - 1, current + 1, 2 * current})
//        {
//            if (next >= 0 && next <= 100000 && visited[next] == -1)
//            {
//                visited[next] = visited[current] + 1;
//                q.push(next);
//
//                if (next == target)
//                    return visited[next];
//            }
//        }
//    }
//
//    return -1;
//}
//
//int main()
//{
//    int start, target;
//    cin >> start >> target;
//
//    cout << BFS(start, target) << endl;
//
//    return 0;
//}


//#define SIZE 100001
//int dp[SIZE];
//int main()
//{
//	int start, target;
//
//	cin >> start >> target;
//
//	// 시작지점과의 거리를 차이만큼으로 초기화
//
//    if (target < start)
//    {
//        swap(target, start);
//    }
//	
//    for (int i = 0; i <= SIZE - 1; i++)
//        dp[i] = abs(start - i);
//
//    for (int i = start + 1; i <= target; i++)
//    {
//        dp[i] = dp[i - 1] + 1;
//
//        if (i % 2 == 0)
//        {
//            dp[i] = min(dp[i], dp[i / 2] + 1);
//            dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
//        }
//    }
//
//	cout << dp[target];
//}