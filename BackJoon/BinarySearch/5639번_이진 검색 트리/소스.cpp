#include <iostream>
#include <vector>
using namespace std;

// 이진 검색 트리 노드 정의
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
        : val(x), left(nullptr), right(nullptr)
    {
    }
};

// 이진 검색 트리에 노드를 삽입하는 함수
void insertNode(TreeNode* &root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val)
    {
        insertNode(root->left, val);
    }
    else
    {
        insertNode(root->right, val);
    }
}

void sol(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    sol(root->left);
    sol(root->right);

    // 현재 노드 값 출력
    cout << root->val << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    TreeNode *root = nullptr;
    int value;

    while (cin >> value)
    {
        insertNode(root, value);
    }

    // 후위 순회로 출력
    sol(root);

    return 0;
}