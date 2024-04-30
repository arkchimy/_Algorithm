#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        q.push(i);
    int last =  q.front();
    while (1)
    {
        q.pop();
        if (q.empty())
        {
            cout << last;
            break;
        }
        last = q.front();
        q.pop();
        q.push(last);
    }

}