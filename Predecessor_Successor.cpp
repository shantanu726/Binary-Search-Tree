/*
Input: root node, key
output: predecessor node, successor node

1. If root is NULL
    then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child
        of right subtree or right child itself.
    return
3. If key is smaller than root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
*/

#include <iostream>
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

int key = 0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key);

void insert(struct Node *root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->key == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new Node(n2);
            break;
        case 'R':
            root->right = new Node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t, k;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct Node *root = NULL;
        Node *pre = NULL;
        Node *suc = NULL;
        while (n--)   
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new Node(n1);
                switch (lr)
                {
                case 'L':
                    root->left = new Node(n2);
                    break;
                case 'R':
                    root->right = new Node(n2);
                    break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        }
        // Inorder(root);
        // Node * target =ptr;
        // printkdistanceNode(root, target, k);
        // cout<<endl;
        cin >> key;
        findPreSuc(root, pre, suc, key);
        if (pre != NULL)
            cout << pre->key;
        else
            cout << "-1";

        if (suc != NULL)
            cout << " " << suc->key << endl;
        else
            cout << " "
                 << "-1" << endl;
    }
    return 0;
}
// } Driver Code Ends

/* BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    pre = NULL;
    suc = NULL;

    Node *temsu = root;
    while (temsu != NULL)
    {
        if (temsu->key > key)
        {
            suc = temsu;
            temsu = temsu->left;
        }
        else
        {
            temsu = temsu->right;
        }
    }

    //                O(n)=T.C......O(1)=S.C
    Node *tempe = root;
    while (tempe != NULL)
    {
        if (tempe->key < key)
        {
            pre = tempe;
            tempe = tempe->right;
        }
        else
        {
            tempe = tempe->left;
        }
    }
}