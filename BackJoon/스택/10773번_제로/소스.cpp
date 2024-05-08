#include <iostream>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<int> s;

    int n;
    cin >> n;
    unsigned long long sum = 0;
    while (n--)
    {
        int temp;
        cin >> temp;
        
        if (temp != 0)
        {
            s.push(temp);
            sum += temp;
        }
        else
        {
            sum -= s.top();
            s.pop();
        }
        
    }
    cout << sum;
}