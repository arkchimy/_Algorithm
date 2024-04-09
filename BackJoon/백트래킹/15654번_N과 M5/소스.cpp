#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>


using namespace std;
int n, m;

vector<int> vec;
void sol(int idx,vector<bool> visited,vector<int> str)
{
    visited[idx] = true;
    str.emplace_back(vec[idx]);
    if (str.size() == m)
    {
        for (int i = 0; i < str.size(); i++)
            cout << str[i] << " ";
        cout << "\n";

        return;
    }

    for (int i =0; i < visited.size(); i++)
    {
        if (visited[i] == false)
            sol(i, visited, str);
    }
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vec.resize(n);
   

    for (int i =0; i < n; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n);
        vector<int> str;
        sol(i,visited,str);
    }
 }