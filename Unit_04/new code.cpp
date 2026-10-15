#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key, height;
    Node *left, *right;
};

bool llDetected = false;

int height(Node *p)
{
    return p == NULL ? 0 : p->height;
}

int balanceFactor(Node *p)
{
    return p == NULL ? 0 :
           height(p->left) - height(p->right);
}

Node* createNode(int key)
{
    Node *p = new Node;
    p->key = key;
    p->height = 1;
    p->left = p->right = NULL;
    return p;
}

// Display tree nodes and their balance factors.
void displayTree(Node *p, string label = "Root")
{
    if (p == NULL)
        return;

    cout << label << ": " << p->key
         << " (BF = " << balanceFactor(p) << ")\n";

    if (p->left)
        displayTree(p->left, "  L");

    if (p->right)
        displayTree(p->right, "  R");
}

// Right rotation for LL imbalance.
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

// Left rotation for RR imbalance.
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

Node* insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
    {
        cout << "Duplicate value ignored.\n";
        return root;
    }

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int bf = balanceFactor(root);

    // LL imbalance.
    if (bf > 1 && key < root->left->key)
    {
        llDetected = true;

        cout << "\nLL imbalance at node "
             << root->key << "\n";

        cout << "Before Rotation:\n";
        displayTree(root);

        cout << "Affected Balance Factors: "
             << root->key << " = " << balanceFactor(root)
             << ", " << root->left->key << " = "
             << balanceFactor(root->left) << "\n";

        Node *newRoot = rightRotate(root);

        cout << "After Right Rotation:\n";
        displayTree(newRoot);

        return newRoot;
    }

    // RR imbalance.
    if (bf < -1 && key > root->right->key)
        return leftRotate(root);

    // LR imbalance.
    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL imbalance.
    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter at least one element.\n";
        return 0;
    }

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nFinal AVL Tree:\n";
    displayTree(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    if (llDetected)
        cout << "\nLL imbalance detected and corrected.\n";
    else
        cout << "\nNo LL imbalance detected.\n";

    return 0;
}
