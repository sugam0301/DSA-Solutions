// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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


vector<int> diagonal(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<int> diagonalNode = diagonal(root);
        for(int i = 0;i<diagonalNode.size();i++)
        cout<<diagonalNode[i]<<" ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


void util(Node *root,map<int,vector<int>>&m,int hd)
{
    if(!root)    return;
    m[hd].push_back(root->data);
    util(root->left,m,hd+1);   
    util(root->right,m,hd);
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>>m;
    int hd;
    util(root,m,0);
    
    vector<int>v;
    for(auto x:m)
        for(auto i:x.second)
            v.push_back(i);
    return v;
}

/*
    Approach: just increase the diagonal distance  by 1 while going to left 
    otherwise dont increase while going to the right
    
    
    How will we do it?
    We can think of a map that can map with 0th diag dist and then 1st...
    
    so it will be of form              map<vector<int>, int>mp
    
    Which traversal?
    BFS its more intuitive in this case
    

                                              \  8                
                                        \       \   
                                         \   3    \ 10
                                          \        \  
                                       1   \   6     \ 14
                                             \        \
                                            4  \   7  13\
                                                \        \
                                            
                       0-> 8,10,14
                       1-> 3,6,7,13
                       2-> 1,4
*/