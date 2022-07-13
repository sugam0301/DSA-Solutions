class Solution {
    TreeNode* first, *last, *prev;
public:
    void inorder(TreeNode* root){
        
        if(!root)   return;
        inorder(root->left);
        
        if(prev and root->val < prev->val)
        {
            if(!first)
            {
                first = prev;
                last = root;
            }
            else
            {
                last = root;
            }
            
        }
        
        
        prev=root;
        
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) 
    {
        first=last=prev=NULL;
        inorder(root);
        swap(first->val,last->val);
    }
};