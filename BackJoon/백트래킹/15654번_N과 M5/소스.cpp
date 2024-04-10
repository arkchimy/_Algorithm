
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vec;
vector<int> result;

void sol(int depth, vector<bool> &visited)
{
    if (depth == m)
    {
        for (int num : result)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            result.push_back(vec[i]);
            sol(depth + 1, visited);
            result.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vec.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    vector<bool> visited(n, false);
    sol(0, visited);

    return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//
//using namespace std;
//int n, m;
//
//vector<int> vec;
//void sol(int idx,vector<bool> visited,vector<int> result)
//{
//    visited[idx] = true;
//    
//    result.emplace_back(vec[idx]);
//    if (result.size() == m)
//    {
//        for (int i = 0; i < result.size(); i++)
//            cout << result[i] << " ";
//        cout << "\n";
//
//        return;
//    }
//
//    for (int i =0; i < visited.size(); i++)
//    {
//        // m == 3 으로 가정
//        if (visited[i] == false)
//            sol(i, visited, result);
//    }
//}
//int main()
//{
//    
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> n >> m;
//    vec.resize(n);
//   
//
//    for (int i =0; i < n; i++)
//    {
//        cin >> vec[i];
//    }
//    sort(vec.begin(), vec.end());
//    for (int i = 0; i < n; i++)
//    {
//        // vec[3] 부터 탐색
//        vector<bool> visited(n);
//        vector<int> result;
//        sol(i, visited, result);
//    }
// }

