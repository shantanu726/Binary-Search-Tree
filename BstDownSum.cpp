/*
Implementation
To check if a node is vertically below the target node, we will use a variable direction. When we visit the right child value of direction will increase by 1 and for the left child it will decrease by 1. Now for any node, if the value of direction is 0 then it is vertical with the target node.

Step 1: set,  res = - target and target_node = NULL;
Step 2: call the find function and pass root and target as a parameter.
Step 3: if res == - target return -1, else return res;

in find function
Step 1: if target_node == NULL and node != NULL
   Step 2: if node->data > target, call find by passing node->left and taget
   Step 3: if node ->data < target, call find by passing node->right and taget
   Step 4: else node ->data == target so visit its ancestor nodes, by calling down and passing node and direction value = 0 as parameter.

in down function
Step 1: if the node is not null
   Step 2: if direction == 0, res += node->data
   Step 3: call down by passing node->left and direction-1
   Step 4: call down by passing node->right and direction+1
*/












//https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1



#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/



/*

//Back-end complete function Template for C++
class Solution{
public:
    long long int res;
    Node *target_node;
    void down(Node *node,int direction){
        if(node){
            if(direction == 0)
                res += node->data;
            down(node->left, direction-1);
            down(node->right, direction+1);
        }
    }
    void find(Node *node,int target){
        if(target_node == NULL){
            if (node){
                if(node->data > target)
                    find(node->left, target);
                else if(node->data < target)
                    find(node->right, target);
                else{
                    target_node = node;
                    down(node, 0);
                }
            }
        }
    }
            
    long long int verticallyDownBST(Node *root,int target){
        
        res = -target;
        target_node = NULL;
        find(root, target);
        if(res == -target) return -1;
        return res;
    }
};
*/
    
   
class Solution{
    long long int ans=0;
public:

void f(Node* root ,int lev){
     if(!root) return ;
     if(lev==0) ans+=root->data;
     f(root->left,lev-1);
     f(root->right,lev+1);
}
Node* find(Node* root ,int tar){
    if(!root) return NULL;
    if(tar>root->data) return find(root->right,tar);
    else if(tar<root->data) return find(root->left,tar);
    else return root;
}
    long long int verticallyDownBST(Node *root,int target){
        Node* node=find(root,target);
        if(!node) return -1;
        f(node,0);
        return ans-node->data;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends