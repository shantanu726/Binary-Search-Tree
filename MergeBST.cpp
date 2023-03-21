/*
Input:
BST1:
       12
     /
    9
   / \
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation:
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
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
class Solution
{
public:
    void solve(Node *root, vector<int> &vecin)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, vecin);
        vecin.push_back(root->data);
        solve(root->right, vecin);
    } // INODDER give the sorted from answer :

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> vecin;
        solve(root1, vecin);
        solve(root2, vecin);

        sort(vecin.begin(), vecin.end());

        return vecin;
    }
};

/*
 void leftNodes (stack<Node*> &s,Node* root)
    {
        s.push(root);
        while(root->left)
        {
            s.push(root->left);
            root = root->left;
        }
    }

    vector<int> merge(Node *root1, Node *root2)
    {
       stack< Node* > s1;
       stack< Node* > s2;

       vector<int> ans;


       leftNodes(s1,root1);
       leftNodes(s2,root2);

       while(!s1.empty()&&!s2.empty())
       {
           if(s1.top()->data <= s2.top()->data)
           {
               Node* temp = s1.top();
               s1.pop();
               ans.push_back(temp->data);
               if(temp->right) leftNodes(s1,temp->right);
           }

           else
           {
               Node* temp = s2.top();
               s2.pop();
               ans.push_back(temp->data);
               if(temp->right) leftNodes(s2,temp->right);
           }

       }

      while(!s1.empty())
       {
           Node* temp = s1.top();
           s1.pop();
           ans.push_back(temp->data);
           if(temp->right) leftNodes(s1,temp->right);
       }

       while(!s2.empty())
       {
           Node* temp = s2.top();
           s2.pop();
           ans.push_back(temp->data);
           if(temp->right) leftNodes(s2,temp->right);

       }


       return ans;


    }
    */

//{ Driver Code Starts.
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends