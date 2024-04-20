#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>

using namespace std;


int main()
{
    unordered_map<string, int> m;

    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> vec(n);


    for(int i =0; i < n; i++)
    {
        cin >> vec[i];
    }
    int len = vec[0].size();

    for (int i = 0; i < vec[0].size();i++)
    {
        string temp;
        int test_len = vec[0].size() - i;
        for (int j =0; j < vec.size(); j++)
        {
            temp = vec[j].substr(i, vec[0].size() - i);
            if (m.find(temp) != m.end())
            {
                test_len = INT_MAX;
                break;
            }
            else
                m[temp] = 0;
        }
        len = min(test_len, len);
    }
    cout << len;
}