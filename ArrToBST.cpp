/*
Given a sorted array. Convert it into a Height balanced Binary Search Tree (BST). Find the preorder traversal of height balanced BST. If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.
Height balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Example 1:

Input: nums = {1, 2, 3, 4}
Output: {2, 1, 3, 4}
Explanation: 
The preorder traversal of the following 
BST formed is {2, 1, 3, 4}:
           2
         /   \
           1     3
               \
                4
 

Example 2:

Input: nums = {1,2,3,4,5,6,7}
Ouput: {4,2,1,3,6,5,7}
Explanation: 
The preorder traversal of the following
BST formed is {4,2,1,3,6,5,7} :
        4
       / \
      2   6
     / \  / \
    1   3 5  7
*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void helper(vector<int> &ans, int l, int r, vector<int> &nums) {

        if(l>r) return;     //getting outside range/array

        int mid=l+(r-l)/2;  //mid of array

        ans.push_back(nums[mid]);   //fill up all the mids in preorder fashion 

        helper(ans, l, mid-1, nums);    //call left first

        helper(ans, mid+1, r, nums);    //then right

    }

    vector<int> sortedArrayToBST(vector<int>& nums) {

        //preorder traversal of a BST can be obtained from inorder travsersal of BST

        //inorder traversal must be in form of that sorted array of data

        //preorder traversal is obtained by performing binary search on sorted array

        vector<int> ans;

        helper(ans, 0, nums.size()-1, nums);

        return ans;

    }


};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends