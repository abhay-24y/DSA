#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left,
        *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *BinaryTree(queue<int> &q)
{
    if (q.front() == -1)
    {
        q.pop();
        return NULL;
    }
    Node *temp = new Node(q.front());
    q.pop();
    temp->left = BinaryTree(q);
    temp->right = BinaryTree(q);
    return temp;
}

void PreOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << "\n";
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}
int main()
{
    queue<int> q;
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    Node *root = BinaryTree(q);
    cout << "PreOrderTraversal : ";
    PreOrderTraversal(root);
    cout << endl;
    cout << "InOrderTraversal : ";
    InOrderTraversal(root);
    cout << endl;
    cout << "PostOrderTraversal : ";
    PostOrderTraversal(root);
    cout << endl;
    cout << "LevelOrderTraversal : \n";
    LevelOrderTraversal(root);
    return 0;
}