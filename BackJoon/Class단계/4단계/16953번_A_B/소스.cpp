#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    unordered_map<ll, int> m;
    queue<pair<ll, int>> q;

    q.push({ a, 0 }); 

    while (!q.empty())
    {
        pair<ll, int> front = q.front();
        q.pop();

        int cur = front.first;
        int cnt = front.second;

        if (cur == b)
        {
            cout << cnt + 1; 
            return 0;
        }

        if (cur * 2 <= b && m.find(cur * 2) == m.end())
        {
            m[cur * 2] = cnt + 1;
            q.push({ cur * 2, cnt + 1 });
        }

      
        ll temp = cur * 10 + 1;
        if (temp <= b && m.find(temp) == m.end())
        {
            m[temp] = cnt + 1;
            q.push({ temp, cnt + 1 });
        }
    }

    cout << -1; 
    return 0;
}

//#include <iostream>
//#include <unordered_map>
//
//#include <queue>
//
//using namespace std;
//
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int a, b;
//	cin >> a >> b;
//
//	unordered_map<int, int> m;
//	queue<pair<int,int>> q;
//
//	q.push({ a ,1});
//
//	while (!q.empty())
//	{
//		pair<int,int> front = q.front();
//		q.pop();
//		if (front.first == b)
//			break;
//		if (m.find(front.first * 2) == m.end()) 
//		{
//			if (front.first * 2 <= b)
//			{
//				m[front.first * 2] = front.second + 1;
//				q.push({ front.first * 2,m[front.first * 2] });
//			}
//		}
//		int temp = front.first * 10  + 1;
//		if (m.find(temp) == m.end())
//		{
//			if (temp <= b)
//			{
//				m[temp] = front.second + 1;
//				q.push({ temp,m[temp] });
//			}
//		}
//	}
//	if (m.find(b) == m.end())
//		m[b] = -1;
//	cout << m[b];
//}