/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.

*/


//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper) {
    if (!n) return true;
    if (n->data <= lower || n->data >= upper) return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}
/*
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  
  
    void fixBST(Node *root, Node *&prev, Node *&first, Node *&second)
{
    if (root == NULL)
        return;
    fixBST(root->left, prev, first, second);
    
    if (prev != NULL && root->data < prev->data)
    {
        if (first == NULL)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    fixBST(root->right, prev, first, second);
}
struct Node *correctBST(struct Node *root)
{
    Node *prev = NULL, *first = NULL, *second = NULL;
    fixBST(root, prev, first, second);
    swap(first->data, second->data);
    return root;

}



/*MY:
void stroe_vec(struct Node* root, vector<int>&vc){
    if(root==NULL){
        return ;
    }
    stroe_vec(root->left, vc);
    vc.push_back(root->data);
    stroe_vec(root->right, vc);
}

void vec_tree(struct Node* root, vector<int>&vc, int idx){
    if(root==NULL){
        return ;
    }
    vec_tree(root->left,vc,idx);
    root->data=vc[idx];idx++;
    vec_tree(root->right,vc,idx);
    
}
struct Node *correctBST(struct Node *root)
{
    vector<int>vc;int idx=0;
    stroe_vec(root,vc);
    sort(vc.begin(), vc.end());
    vec_tree(root,vc,idx);
    
    
    return root;
*/

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        root = ob.correctBST(root);

        // check 1: is tree now a BST
        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if (!compare(root, duplicate, mismatch)) {
            // false output from this function indicates change in structure of
            // tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends