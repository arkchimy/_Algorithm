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

        }

        if (str.compare("size") == 0)
        {
            cout << q.size() << "\n";
       
        }
        if (str.compare("empty") == 0)
        {
            if (q.empty())
                cout << "1\n";
            else
                cout << "0\n";
 
        }
        if (str.compare("pop_front") == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
       
        }
        if (str.compare("pop_back") == 0)
        {
            if (q.empty())
                cout << "-1\n";
            else
            {
                cout << q.back() << "\n";
                q.pop_back();
            }
     
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
        if (str.compare("push_front") == 0)
        {
            cin >> num;
            q.push_front(num);    
        }
        if (str.compare("push_back") == 0)
        {
            cin >> num;
            q.push_back(num);
        }
        
    }
}
