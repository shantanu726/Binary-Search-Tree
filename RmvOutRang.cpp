/*
Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside the given range. The modified tree should also be BST.

Example 1:

Input:
Range = [-10, 13]
Lightbox
Output:
-8 6 7 13
Explanation:
Nodes with values -13, 14 and 15 are 
outside the given range and hence are 
removed from the BST.

BinaryTreeModified2
This is the resultant BST and it's 
inorder traversal is -8 6 7 13.
Example 2:

Input:
Range = [2, 6]
        14
      /    \
     4      16
    / \     /
   2   8   15
  / \  / \
 -8  3 7  10
Output:
2 3 4
Explanation:
After removing nodes outside the range, 
the resultant BST looks like:
               4
              /
             2
              \
                3 
The inorder traversal of this tree is: 2 3 4
*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    Node* left;
    Node* right;
};*/



/*class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if(root == NULL) return NULL;
        
        if(root->data < l) 
            return removekeys(root->right, l, r);
        if(root->data > r) 
            return removekeys(root->left, l, r);
        
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        
        return root;
    }
};*/



class Solution {
    public:
   Node * removekeys(Node* root, int min, int max) {
        
         // Base Case
   if (root == NULL)
      return NULL;

   // First fix the left and right subtrees of root
   root->left =  removekeys(root->left, min, max);
   root->right =  removekeys(root->right, min, max);

   // Now fix the root.  There are 2 possible cases 
   // for root 1.a) Root's key is smaller than min
   // value (root is not in range)
  if (root->data < min)
  {
      Node *rChild = root->right;
      delete root;
      return rChild;
  }
  // 1.b) Root's key is greater than max value
  // (root is not in range)
  if (root->data > max)
  {
      Node *lChild = root->left;
      delete root;
      return lChild;
  }
   // 2. Root is in range
   return root;
}
    
};

//{ Driver Code Starts.
/* Driver program to test size function*/
int main() {

    int t;
    cin >> t;
    getchar();
    while (t--) {
        int l, r;
        cin >> l >> r;

        string ln;
        getline(cin, ln);

        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution obj;
        Node* head = obj.removekeys(root, l, r);

        inorderTraversal(head);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends