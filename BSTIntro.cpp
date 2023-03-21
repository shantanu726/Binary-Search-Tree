#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertBST(root->right, d);
    }
    else
    {
        root->left = insertBST(root->left, d);
    }
}

void inp(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

void inorderView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderView(root->left);
    cout << root->data << " ";
    inorderView(root->right);
}

Node *minval(Node *root)
{
    Node *tem = root;
    while (tem->left != NULL)
    {
        tem = tem->left;
    }
    return tem;
}

Node *maxval(Node *root)
{
    Node *tem = root;
    while (tem->right != NULL)
    {
        tem = tem->right;
    }
    return tem;
}

Node *deleteA(Node *root, int val)
{ // T.C=O(N)---S.C=O(N)
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        // 1 child
        // 1.LEFT CHILD:
        if (root->left != NULL && root->right == NULL)
        {
            Node *tem = root->left;
            delete root;
            return tem;
        }
        // 1.RIGHT CHILD:
        if (root->left == NULL && root->right != NULL)
        {
            Node *tem = root->right;
            delete root;
            return tem;
        }

        // 2 child

        if (root->left != NULL && root->right != NULL)
        {
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deleteA(root->right, mini);
        }
    }
    else if (root->data > val)
    {
        root->left = deleteA(root->left, val);
        // vai value <choto> tai BST ar <left> jayea dakhta hobe:
        return root;
    }

    else if (root->data < val)
    {
        // vai value <boro> tai BST ar <right> jayea dakhta hobe:
        root->right = deleteA(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    cout << "\n";
    cout << "\n";
    cout << "Enter data for BST" << endl;
    inp(root);

    cout << "BST view at inorder <AT SORTED FROM > ";
    inorderView(root);
    cout << "\n";

    cout << "The mini value in BST is : " << minval(root)->data << endl;

    cout << "The max value in BST is : " << maxval(root)->data << endl;

    cout << "\n";
    cout << "\n";

    cout << "Enter the deleted Key To DELET : " << endl;

    deleteA(root, 50);
    cout << "BST view at inorder <AT SORTED FROM > ";
    inorderView(root);

    cout << "\n";
    cout << "\n";
    return 0;
}

/*  AT INORDER TREE TRAVEL IT WILL GIVE RESULT IN SORTED ORDER ---------- BST*/