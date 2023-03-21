/*
 Given a Binary Search Tree. Find sum of all elements smaller than and equal to Kth smallest element.

Example 1:

Input: 
          20
        /    \
       8     22
     /    \
    4     12
         /    \
        10    14   , K=3

Output: 22
Explanation:
Sum of 3 smallest elements are: 
4 + 8 + 10 = 22
Example 2:
Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8 , K=2

Output: 9
Explanation:
The sum of two smallest elements 
is 4+5=9.
*/



//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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

int sum(Node* root, int k);



int main()
{

	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int k;
		cin >> k;
		Node* root = buildTree(s);
		cout << sum(root, k) << endl;
	
	}
	return 1;
}






// } Driver Code Ends


//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1

/*
 void solve(Node* root,vector<int>&v){
      if(root==NULL) return ;
      
      solve(root->left,v);
          v.push_back(root->data);
      solve(root->right,v);
  }
int sum(Node* root, int k) 
{ 
  
    vector<int>v;
    if(root==NULL) return 0;
    
    solve(root,v);
    
    int s=0;
    for(int i=0;i<k;i++ ){
        s=s+v[i];
    }
    return s;
} 
*/


/*
void helper(Node* root, int k, int &sum, int &cnt)
{
    if (root == NULL)
    {
        return;
    }
    helper(root->left, k, sum, cnt);
    if (cnt < k)
    {
        sum = sum + root->data;
        cnt++;
    }
    helper(root->right, k, sum, cnt);
}
int sum(Node* root, int k) 
{ 
    int sum = 0;
    int cnt = 0;
    helper(root, k, sum, cnt);
    return sum;
} 

*/

/*void inorder(Node* root,int &sum,int& k){
    if(!root)   return;
    if(k==0)    return;
    inorder(root->left,sum,k);
    if(k>0){
        sum+=root->data;
        k--;
    }
    inorder(root->right,sum,k);
}
int sum(Node* root, int k) 
{ 
  
    // Your code here
    int sum=0;
    inorder(root,sum,k);
    return sum;
}*/

/*MORRIS TRAVEL S.P (1) T.c (K)*/

int sum(Node* root, int k)
{
    Node *curr = root;
    int count = 0, sum = 0;
    while(curr) {
        if(curr->left == NULL) {
            if(count < k)
                sum += curr->data;
            count++;
            if(count == k)
                return sum;
            curr = curr->right;
        } 
        else {
            Node *nxt = curr->left;
            while(nxt->right != NULL and nxt->right != curr)
                nxt = nxt->right;
            if(nxt->right == NULL) {
                nxt->right = curr;
                curr = curr->left;
            }
            else {
                nxt->right = NULL;
                if(count < k)
                    sum += curr->data;
                count++;
                if(count == k)
                    return sum;
                curr = curr->right;
            }
        }
    }
}


































