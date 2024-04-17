#include <iostream>
#include <string>
using namespace std;

int dp[1001][10001];

int sol(const string& s1,const string& s2)
{
    int m = s1.length();
    int n = s2.length();

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n]; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int result = sol(s1, s2);
    cout << result;

    return 0;
}