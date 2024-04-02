#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    unordered_map<string, int> trees; // ������ ������ ������ ������ �ؽ� ��
    string tree;

    int total = 0; // ��ü ������ ����

    // �Է� �ޱ�
    while (true) 
    {
    
        getline(cin, tree);
        if (tree.empty())
            break;
        trees[tree]++;
        total++;
    }
    vector<pair<string, int>> vec(trees.begin(),trees.end());
    
    sort(vec.begin(), vec.end());

    for (auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        float  result = float(iter->second) / total * 100.f;
        cout  << iter->first << " " << fixed << setprecision(4) << result << '\n';
    }

}