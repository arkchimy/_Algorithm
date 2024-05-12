#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> result(n);

    deque<int> dp(n);
    for (int i = 0; i < n; i++)
        dp[i] = i + 1;
    for (int j =0; j < n; j++)
    {
        int front;
        for (int i = 0; i < k - 1; i++)
        {
            int front = dp.front();
            dp.pop_front();
            dp.push_back(front);
        }
        front = dp.front();
        dp.pop_front();
        result[j] = front;
        
    }
    cout << "<";
    for (int i =0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << ">";
}
