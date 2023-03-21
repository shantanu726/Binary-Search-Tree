/*
APP1::::::
Lowest Common Ancestor in a Binary Search Tree using Recursion:
To solve the problem follow the below idea:

For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. 

So just recursively traverse the BST , if node’s value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST)

Follow the given steps to solve the problem:

Create a recursive function that takes a node and the two values n1 and n2.
If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for the right subtree.
If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for the left subtree.
If both the above cases are false then return the current node as LCA.

*/

// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left, *right;
};

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
	if (root == NULL)
		return NULL;

	// If both n1 and n2 are smaller
	// than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);

	// If both n1 and n2 are greater than
	// root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);

	return root;
}

/* Helper function that allocates
a new node with the given data.*/
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

/* Driver code*/
int main()
{
	// Let us construct the BST
	// shown in the above figure
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	// Function calls
	int n1 = 10, n2 = 14;
	node* t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;
	return 0;
}
/*
Time Complexity: O(H). where H is the height of the tree.
Auxiliary Space: O(H), If recursive stack space is ignored, the space complexity of the above solution is constant.
*/



/*
APP:2:::::::: using Morris algorithm
T.S (N)---S.c(1)



// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node *left, *right;
};


node* lca(node* root, int n1, int n2)
{
	while (root != NULL) {
		// If both n1 and n2 are smaller than root,
		// then LCA lies in left
		if (root->data > n1 && root->data > n2)
			root = root->left;

		// If both n1 and n2 are greater than root,
		// then LCA lies in right
		else if (root->data < n1 && root->data < n2)
			root = root->right;

		else
			break;
	}
	return root;
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}


int main()
{
	// Let us construct the BST
	// shown in the above figure
	node* root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	// Function calls
	int n1 = 10, n2 = 14;
	node* t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is "
		<< t->data << endl;
	return 0;
}


*/