#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;



int main()
{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    
    for (int i =0; i < n ; i++)
    {
        cin >> vec[i];
    }

    vector<int> temp(vec);
    
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    vector<int> answer(n);
    for (int i =0; i < n; i++)
    {
        cout << lower_bound(temp.begin(), temp.end(), vec[i]) - temp.begin() << " ";
    }
    
    
}