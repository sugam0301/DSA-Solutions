class Solution {
public:
    
    void flatten(TreeNode* root) 
    {
        TreeNode *head = NULL, *tail = NULL;
        if(root==NULL)   return;
        
        //dfs traversal of tree using stack (preorder)
        stack<TreeNode *>s;
        s.push(root);
        
        while(s.size())
        {
            TreeNode *curr = s.top(); s.pop();
            
            if(!head)
            {
                head = tail = curr;
            }
            else
            {
                tail -> right = curr;
                tail -> left = nullptr;
                tail = tail -> right;
            }
            
            
            if(curr->right) s.push(curr->right);
            if(curr->left)  s.push(curr->left);
            
            
        }
        return;
    }
};