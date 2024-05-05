#include <iostream>

using namespace std;

int answer;

void sol(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return;
    }
    answer++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    while (n--)
    {
        int temp;
        cin >> temp;
        if (temp <= 1)
            continue;
        sol(temp);
    }
    cout << answer;
}