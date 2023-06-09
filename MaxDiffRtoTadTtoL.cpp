/*
The problem says that, You are given a BST and a target value.

You have to maximize the difference given by the formula below:

diff = [sum of node.data from root to target ]  - [ sum of node.data from target to leaf ].
*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++



class Solution {
public:
    int find(Node* root, int target, Node** targetNode) {
        if (root == NULL) return INT_MIN;
        if (root->data == target) {
            *targetNode = root;
            return target;
        }
        
        if (target > root->data) {
            return root->data + find(root->right, target, targetNode);
        } else {
            return root->data + find(root->left, target, targetNode);
        }
    }
    
    int solve(Node* root) {
        if (root == NULL) return INT_MAX / 2;
        if (root->left == NULL && root->right == NULL) return root->data;
        
        int left = root->data + solve(root->left);
        int right = root->data + solve(root->right);
        
        return min(left, right);
    }
    
    int maxDifferenceBST(Node* root, int target) {
        Node* targetNode = NULL;
        int rootToTarget = find(root, target, &targetNode);
        
        if (targetNode == NULL) return -1;
        
        int targetToLeaf = solve(targetNode);
        
        return rootToTarget - targetToLeaf;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}


/*
int x = -1 ;
     void solve( Node *root , int target , Node*&node , int curr )
    {
        if(!root)
        {
            return ;
        }
        
        if( root->data == target )
        {
            node = root ;
            x = curr ;
            return ;
        }
        
        if( root->data > target )
        {
            solve( root->left , target , node ,  curr + root->data ) ;
        }
        else{
           solve( root->right , target , node ,  curr + root->data ) ;
        }
        
        
        
    }
    
    int solve2( Node *root )
    {
        if(!root->left && !root->right )
        {
            return root->data ;
        }
        
        if(!root->left && root->right )
        {
            return root->data + solve2( root->right )  ;
        }
        
        if(root->left && !root->right )
        {
            return root->data + solve2( root->left )  ;
        }
        
        return min( root->data + solve2( root->left ) , root->data + solve2( root->right ) ) ;
        
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        
        Node *node = NULL ;
       
        
        solve( root , target , node ,  0 ) ;
        
        if( node == NULL ) return -1 ;
        
        int ans = INT_MIN ;
        
        int mn = solve2(node) ;
        
        return x - mn + target  ;
    }
    */
