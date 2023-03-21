/*

Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

Examples: 

Input: arr[] = {1, 2, 3}
Output: A Balanced BST
      2
    /  \
 1     3 
Explanation: all elements less than 2 are on the left side of 2 , and all the elements greater than 2 are on the right side

Input: arr[] = {1, 2, 3, 4}
Output: A Balanced BST
          3
        /  \
     2    4
   /
1

Set The middle element of the array as root.
Recursively do the same for the left half and right half.
Get the middle of the left half and make it the left child of the root created in step 1.
Get the middle of the right half and make it the right child of the root created in step 1.
Print the preorder of the tree.

Time Complexity: O(N) 
Auxiliary Space: O(H) ~= O(log(N)), for recursive stack space where H is the height of the tree.
*/

// C++ program to print BST in given range
#include<bits/stdc++.h>
using namespace std;

/* A Binary Tree node */
class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
};

TNode* newNode(int data);

/* A function that constructs Balanced
Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[],
						int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	TNode *root = newNode(arr[mid]);

	/* Recursively construct the left subtree
	and make it left child of root */
	root->left = sortedArrayToBST(arr, start,
									mid - 1);

	/* Recursively construct the right subtree
	and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	TNode *root = sortedArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

	return 0;
}

// This code is contributed by rathbhupendra
