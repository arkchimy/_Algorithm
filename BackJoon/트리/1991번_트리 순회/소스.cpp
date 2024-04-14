#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node(char data) 
        : left(nullptr), right(nullptr), mData(data){}
    Node *left;
    Node *right;
    char mData;
};
vector<Node *> nodes;
void preorder(Node* node)
{
    if (node == nullptr)
        return;
    cout << node->mData;
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->mData;
    inorder(node->right);
}
void postorder(Node *node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->mData;
}
int main()
{
    int n;
    cin >> n;

    char a, b, c;

    nodes.resize(n,nullptr);
    while (n--)
    {
        cin >> a >> b >> c;
        int parent = a - 'A';
        if (nodes[parent] == nullptr)
        {
            nodes[parent] = new Node(a);
            nodes[parent]->mData = a;
        }
        int left = b - 'A';
        if (b != '.')
        {
            nodes[left] = new Node(b);
            nodes[left]->mData = b;
            nodes[parent]->left = nodes[left];
        }
        int right = c - 'A';
        if (c != '.')
        {
            nodes[right] = new Node(c);
            nodes[right]->mData = c;
            nodes[parent]->right = nodes[right];
        }
    }

    preorder(nodes[0]);
    cout << "\n";
    inorder(nodes[0]);
    cout << "\n";
    postorder(nodes[0]);

    for (Node *node : nodes)
    {
        if (node != nullptr)
            delete node;
    }

}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct Node
//{
//    char data;
//    Node *left;
//    Node *right;
//
//    Node(char d) : data(d), left(nullptr), right(nullptr)
//    {
//    }
//};
//
//// ���� ��ȸ (Root-Left-Right)
//void preorder(Node *node)
//{
//    if (node == nullptr)
//        return;
//    cout << node->data;    // ���� ���� ��� ���
//    preorder(node->left);  // ���� ����Ʈ�� ��ȸ
//    preorder(node->right); // ������ ����Ʈ�� ��ȸ
//}
//
//// ���� ��ȸ (Left-Root-Right)
//void inorder(Node *node)
//{
//    if (node == nullptr)
//        return;
//    inorder(node->left);  // ���� ����Ʈ�� ��ȸ
//    cout << node->data;   // ���� ��� ���
//    inorder(node->right); // ������ ����Ʈ�� ��ȸ
//}
//
//// ���� ��ȸ (Left-Right-Root)
//void postorder(Node *node)
//{
//    if (node == nullptr)
//        return;
//    postorder(node->left);  // ���� ����Ʈ�� ��ȸ
//    postorder(node->right); // ������ ����Ʈ�� ��ȸ
//    cout << node->data;     // ���������� ���� ��� ���
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<Node *> nodes(26, nullptr); // ��带 ������ ����
//
//    // Ʈ�� ����
//    for (int i = 0; i < n; ++i)
//    {
//        char parent, left, right;
//        cin >> parent >> left >> right;
//
//        int parentIdx = parent - 'A';
//        if (nodes[parentIdx] == nullptr)
//        {
//            nodes[parentIdx] = new Node(parent);
//        }
//
//        if (left != '.')
//        {
//            int leftIdx = left - 'A';
//            nodes[leftIdx] = new Node(left);
//            nodes[parentIdx]->left = nodes[leftIdx];
//        }
//
//        if (right != '.')
//        {
//            int rightIdx = right - 'A';
//            nodes[rightIdx] = new Node(right);
//            nodes[parentIdx]->right = nodes[rightIdx];
//        }
//    }
//
//    Node *root = nodes[0]; // ��Ʈ ���
//
//    // ���� ��ȸ
//    preorder(root);
//    cout << endl;
//
//    // ���� ��ȸ
//    inorder(root);
//    cout << endl;
//
//    // ���� ��ȸ
//    postorder(root);
//    cout << endl;
//
//    // ���� �Ҵ�� ��� �޸� ����
//    for (Node *node : nodes)
//    {
//        if (node != nullptr)
//        {
//            delete node;
//        }
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//
//struct Node
//{
//    Node() : val(-1), left(nullptr), right(nullptr)
//    {
//    }
//    int val;
//    Node* left;
//    Node* right;
//};
//vector<Node> vec;
//
//int n;
//void PreorderTraversal(Node* node)
//{
//    if (node  == nullptr)
//        return;
//
//    char ch = node->val + 'A';
//    cout << ch;
//    PreorderTraversal(node->left);
//    PreorderTraversal(node->right);
//}
//void InorderTraversal(int idx)
//{
//    if (idx >= n)
//        return;
//    if (vec[idx].val == -1)
//        return;
//    
//    InorderTraversal(idx * 2 + 1);
//    char ch = vec[idx].val + 'A';
//    cout << ch;
//    InorderTraversal(idx * 2 + 2);
//    
//}
//void PostorderTraversal(int idx)
//{
//    if (idx >= n)
//        return;
//    if (vec[idx].val == -1)
//        return;
//
//    PostorderTraversal(idx * 2 + 1);
//    PostorderTraversal(idx * 2 + 2);
//    char ch = vec[idx].val + 'A';
//    cout << ch;
//    
//}
//int main()
//{
//    
//    cin >> n;
//    
//
//    vec.resize(pow(2,n));
//    char a, b, c;
//    for (int i =0; i < n ; i++)
//    {
//        cin >> a >> b >> c;
//        vec[i].val = a - 'A';
//
//        
//        if (b == '.')
//            vec[i * 2 + 1].val = -1;
//        else
//        {
//            vec[i].left = &vec[i * 2 + 1];
//            vec[i * 2 + 1].val = b - 'A';
//        }
//        
//       
//        if (c == '.')
//            vec[i * 2 + 2].val = -1;
//        else
//        {
//        
//            vec[i].right = &vec[i * 2 + 2];
//            vec[i * 2 + 2].val = c - 'A';
//        }
//        
//    }
//
//    PreorderTraversal(&vec[0]);
//    cout << "\n";
//    /*InorderTraversal(0);
//    cout << "\n";
//    PostorderTraversal(0);*/
//}