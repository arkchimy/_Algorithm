#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> parent; // 각 친구의 부모 노드를 저장하는 해시 맵
unordered_map<string, int> networkSize; // 각 친구 네트워크의 크기를 저장하는 해시 맵

// 루트 노드를 찾는 함수
string findRoot(string node) 
{
    if (parent[node] == node) 
    {
        return node; // 루트 노드일 경우 자기 자신을 반환
    }
    return parent[node] = findRoot(parent[node]); // 경로 압축을 통해 루트 노드를 찾고 반환
}

// 두 친구 네트워크를 합치는 함수
void mergeNetwork(string node1, string node2) 
{
    string root1 = findRoot(node1);
    string root2 = findRoot(node2);

    // 루트 노드가 다를 경우, 한 네트워크를 다른 네트워크에 합침
    if (root1 != root2) {
        parent[root2] = root1; // 더 작은 번호의 루트를 부모로 설정
        networkSize[root1] += networkSize[root2]; // 네트워크 크기 갱신
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;

    while (n--) {
        parent.clear();
        networkSize.clear();

        cin >> m;

        while (m--) 
        {
            string s1, s2;
            cin >> s1 >> s2;

            // 처음 등장하는 친구일 경우, 자기 자신을 부모로 설정하고 네트워크 크기를 1로 초기화
            if (parent.find(s1) == parent.end()) 
            {
                parent[s1] = s1;
                networkSize[s1] = 1;
            }
            if (parent.find(s2) == parent.end()) 
            {
                parent[s2] = s2;
                networkSize[s2] = 1;
            }

            // 두 친구 네트워크를 합침
            mergeNetwork(s1, s2);

            // 최상위 부모 노드의 네트워크 크기 출력
            cout << networkSize[findRoot(s1)] << '\n';
        }
    }

    return 0;
}

//#include <iostream>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int n,m;
//	cin >> n;
//
//	while (n--)
//	{
//		unordered_map<string, string> h;
//		cin >> m;
//		while (m--)
//		{
//			
//		
//			string s1, s2;
//			cin >> s1 >> s2;
//
//			if (h.find(s1) == h.end())
//				h[s1] = s1;
//			if (h.find(s2) == h.end())
//				h[s2] = s2;
//
//			if (s1 < s2)
//			{
//				h[s1] = min(s1,min(h[s1],h[s2]));
//				h[s2] = h[s1];
//			}
//			else
//			{
//				h[s1] = min(s2, min(h[s1], h[s2]));
//				h[s2] = h[s1];
//			}
//			string target = h.begin()->second;
//			int sum = 0;
//			for (auto iter = h.begin(); iter != h.end(); iter++)
//			{
//				if (iter->second != target)
//					iter->second = min(h[iter->first], h[iter->second]);
//				if (iter->second == target)
//					sum++;
//			}
//			cout << sum << "\n";
//		
//
//		}
//	}
//	
//}