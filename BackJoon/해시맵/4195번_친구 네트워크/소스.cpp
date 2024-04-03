#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> parent; // �� ģ���� �θ� ��带 �����ϴ� �ؽ� ��
unordered_map<string, int> networkSize; // �� ģ�� ��Ʈ��ũ�� ũ�⸦ �����ϴ� �ؽ� ��

// ��Ʈ ��带 ã�� �Լ�
string findRoot(string node) 
{
    if (parent[node] == node) 
    {
        return node; // ��Ʈ ����� ��� �ڱ� �ڽ��� ��ȯ
    }
    return parent[node] = findRoot(parent[node]); // ��� ������ ���� ��Ʈ ��带 ã�� ��ȯ
}

// �� ģ�� ��Ʈ��ũ�� ��ġ�� �Լ�
void mergeNetwork(string node1, string node2) 
{
    string root1 = findRoot(node1);
    string root2 = findRoot(node2);

    // ��Ʈ ��尡 �ٸ� ���, �� ��Ʈ��ũ�� �ٸ� ��Ʈ��ũ�� ��ħ
    if (root1 != root2) {
        parent[root2] = root1; // �� ���� ��ȣ�� ��Ʈ�� �θ�� ����
        networkSize[root1] += networkSize[root2]; // ��Ʈ��ũ ũ�� ����
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

            // ó�� �����ϴ� ģ���� ���, �ڱ� �ڽ��� �θ�� �����ϰ� ��Ʈ��ũ ũ�⸦ 1�� �ʱ�ȭ
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

            // �� ģ�� ��Ʈ��ũ�� ��ħ
            mergeNetwork(s1, s2);

            // �ֻ��� �θ� ����� ��Ʈ��ũ ũ�� ���
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