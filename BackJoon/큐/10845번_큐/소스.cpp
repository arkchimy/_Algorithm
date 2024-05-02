#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    deque<int> q;

    int n, num;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        if (str.compare("front") == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
            continue;
        }
       
        if (str.compare("size") == 0)
        {
            cout << q.size() << "\n";
            continue;
        }
        if (str.compare("empty") == 0)
        {
            if (q.empty())
                cout << "1\n";
            else
                cout << "0\n";
            continue;
        }
        if (str.compare("pop") == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
            continue;
        }
        if (str.compare("back") == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.back() << "\n";
            }
            continue;
        }
        cin >> num;
        q.push_back(num);

    }
}
