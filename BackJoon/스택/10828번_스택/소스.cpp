#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<int> s;
    
    int n,num;
    cin >> n;
    string str;
    while (n--)
    {
        cin >> str;
        if (str.compare("top") == 0 )
        {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.top() << "\n";
            continue;
        }
        if (str.compare("size") == 0)
        {
            cout << s.size() << "\n";
            continue;
        }
        if (str.compare("empty") == 0)
        {
            if (s.empty())
                cout << "1\n";
            else
                cout << "0\n";
            continue;
        }
        if (str.compare("pop") == 0)
        {
            if (s.empty())
                cout << "-1\n";
            else
            {
                cout << s.top() << "\n";
                s.pop();
            }
            continue;
        }
        cin >> num;
        s.push(num);
        
    }
}
