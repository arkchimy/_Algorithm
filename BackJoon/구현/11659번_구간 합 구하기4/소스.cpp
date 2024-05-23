#include <iostream>
#include <vector>

using namespace std;


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

 
    vector<int> sum_vec;
    int a, b;
    cin >> a >> b;

    sum_vec.resize(a + 1,0);

    for (int i =1;  i <= a; i ++)
    {
        int temp;
        cin >> temp;
        sum_vec[i] = sum_vec[i - 1] + temp;
    
    }
    while (b--)
    {
        pair<int, int> p;
        cin >> p.first >> p.second;
  
        cout << sum_vec[p.second] - sum_vec[p.first - 1] << "\n";
    }
    
}