#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
};

int height(Node *n)
{
    return n == NULL ? 0 : n->height;
}

Node* createNode(int x)
{
    Node *n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

int balance(Node *n)
{
    return n == NULL ? 0 :
           height(n->left) - height(n->right);
}

Node* insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    if (balance(root) > 1 && key < root->left->data)
        return rightRotate(root);

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 30);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nRoot Node: " << root->data;

    return 0;
}
