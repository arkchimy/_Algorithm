#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    long long n, m, stick = -1;
    long long start, end, mid, sum;
    cin >> n >> m;

    vector<int> vec;
    vec.resize(n);

    for (int i = 0; i < n; i++) 
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    start = 0;
    end = vec.size() - 1;

    while (start <= end) 
    {
        sum = 0;
        mid = (start + end) / 2;

        for (int i = 0; i < n; i++) 
        {
            if (vec[i] - mid > 0) 
                sum += vec[i] - mid;
        }

        if (sum >= m) 
        {
            start = mid + 1;
            if (mid > stick) 
                stick = mid;
        }
        else 
            end = mid - 1;
    }

    cout << stick;

}