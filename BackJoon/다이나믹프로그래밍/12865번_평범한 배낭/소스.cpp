#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        int weight, value;
        cin >> weight >> value;

        // 무게가 5가 입력됬을 경우
        // 가질 수 있는 무게에서 weight 가 될때까지 빼면 7 ~ 5 까지 하게됌.
        for (int w = K; w >= weight; --w)
            dp[w] = max(dp[w], dp[w - weight] + value);
        
    }

    cout << dp[K] << '\n';

    return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, K;
//    cin >> N >> K;
//    int W, V;
//
//    vector<pair<int, int>> vec;
//    vec.reserve(N);
//    while (N--)
//    {
//        cin >> W >> V;
//        vec.emplace_back(W, V);
//    }
//    sort(vec.begin(), vec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
//        {
//        if (p1.first == p2.first)
//            return p1.second > p2.second;
//        return p1.first < p2.first;
//        }
//     );
//    int left=0, right = 0;
//    int weight = 0;
//    int sum = 0;
//    int result = sum;
//    while (left <= right)
//    {
//        if (right == vec.size())
//            break;
//        if(weight + vec[right].first <= K)
//        {
//            weight += vec[right].first;
//            sum += vec[right].second;
//            right++;
//        }
//        else
//        {
//            weight -= vec[left].first;
//            sum -= vec[left].second;
//            left++;
//        }
//        result = max(result, sum);
//    }
//    cout << result;
//
//}