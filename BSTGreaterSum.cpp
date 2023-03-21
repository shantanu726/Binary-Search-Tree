/*
Lamp
Looking for a Way to Crack the Best Product Companies?! Try THIS GFG Course !

Given a BST, transform it into greater sum tree where each node contains sum of all nodes greater than that node.

Example 1:

Input:
           2
         /    \
        1      6
              /  \
             3    7
Output: 18 16 13 7 0
Explanation:
Every node is replaced with the 
sum of nodes greater than itself. 
The resultant tree is:
               16
             /    \
           18       7
                  /   \
                 13    0
Example 2:

Input:
          2
         /
        1
Output: 2 0
Explanation:
The resultant tree is :
             0
            /
          2

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A BST node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

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



// } Driver Code Ends
//User function Template for C++

/*struct Node
{
	int data;
	struct Node *left, *right;
};*/


/*

void sol(Node *root,int &i)
{
    {
        if(root == NULL){
            return;
        }
        int m=root->data;
        sol(root->right,i );
        root->data=root->data+i;
        i=root->data;
        root->data=i-m;
        sol(root->left,i);

    }
    
}
    
    void transformTree(struct Node *root)
    {
        //code here
        int i=0;
    sol(root,i);
    // return root;
    }*/
    
    
    
class Solution
{
    public:
    void solve(Node*root, int &sum){
        if(root==NULL) return;
        
        solve(root->right,sum);
        sum=sum+root->data;
        root->data=sum-root->data;
        solve(root->left,sum);
    }
    void transformTree(struct Node *root)
    {
        int sum=0;
        solve(root,sum);
    }
};

//{ Driver Code Starts.

void printInorder(struct Node *root)
{
	if (root == NULL) return;

	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

// Driver Program to test above functions
int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{

		string inp, ch;
		getline(cin, inp);
	
		struct Node* root = buildTree(inp);

        Solution ob;
		ob.transformTree(root);
		printInorder(root);
        
        cout<<"\n";
	}


	return 0;
}


// } Driver Code Ends