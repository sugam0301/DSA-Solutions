// { Driver Code Starts
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


 // } Driver Code Ends
//Function to count number of nodes in BST that lie in the given range.
class Solution{
    void inorder(Node *root, int &cnt, int l, int h)
    {
        if(!root)   return ;
        inorder(root->left, cnt,l,h);
        if(root->data >= l and root->data<=h)
            cnt++;
        inorder(root->right, cnt,l,h);
    }
    
public:
    int getCount(Node *root, int l, int h)
    {
        int cnt = 0;
        inorder(root,cnt,l,h);    
        return cnt;
    }
};



/*
We have to count the no of nodes in the bst that lie in the given range  let say b/w l and r inclusive
Approach 1:
1. Simple store the inorder in the vector
2. Now just check for the lower_bound of r and lower_bound of l -> subtract them

3,5,6,11,12
range is [4,10]

4->1
10->3
3-1+1

lower_bound(r) - lower_bound(l) + 1

Approach 2:
Same as before but before pushing into the vector we check if it falls in the range.
then do return the size of vector.





*/






// { Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		string s;
		getline(cin >> ws, s);
		int l, r;
		cin >> l >> r;
		Solution ob;
		Node* root = buildTree(s);
		cout << ob.getCount(root, l, r) << endl;
		
	}
	return 1;
}
  // } Driver Code Ends