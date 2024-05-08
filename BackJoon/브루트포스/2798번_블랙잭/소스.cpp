#include <iostream>
#include <vector>
using namespace std;


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<int> vec(n);

    for (int i =0; i < n ; i++)
    {
        cin >> vec[i];
    }

    int result = 0;
    for (int i = 0; i < n - 2; i++)
    {   
        int sum = vec[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            sum += vec[j];
            for (int k = j + 1; k < n; k++)
            {
                sum += vec[k];
                if (sum <= m && result < sum)
                {
                    result = sum;
                }
                sum -= vec[k];
            }
            sum -= vec[j];

        }
            
    }
    cout << result;
}