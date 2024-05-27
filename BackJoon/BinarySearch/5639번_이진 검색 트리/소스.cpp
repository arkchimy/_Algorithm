#include <iostream>
#include <vector>
using namespace std;

// ���� �˻� Ʈ�� ��� ����
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

// ���� �˻� Ʈ���� ��带 �����ϴ� �Լ�
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

    // ���� ��� �� ���
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

    // ���� ��ȸ�� ���
    sol(root);

    return 0;
}