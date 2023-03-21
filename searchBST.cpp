//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node *root, int x);

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << search(root, s);
        cout << endl;
    }
}

// } Driver Code Ends

// Function to search a node in BST.

bool search(Node *root, int x)
{

    /*
     if(root==NULL){
        return 0;
    }
     if(x==root->data){
        return 1;
    }                           // T.C  O(n) .......... S.C O(n)
    if(x>root->data){
      return   search(root->right,x);
    }if(x<root->data){
      return  search(root->left,x);
    }
    */
    Node *tem = root;
    while (tem != NULL)
    {
        if (tem->data == x)
        {
            return 1;
        } // S>C O(1);
        if (tem->data > x)
        {
            tem = tem->left;
        }
        else
        {
            tem = tem->right;
        }
    }
    return 0;
}
