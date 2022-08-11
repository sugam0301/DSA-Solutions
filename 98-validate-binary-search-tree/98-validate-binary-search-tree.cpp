class Solution {
public:
    bool isbst(TreeNode *root,long l,long r)
    {
        if(root==nullptr) return true;
        if(root->val <= l || root->val >= r || l>r)
            return false;
        
        return  (root->val>l && root->val<r  &&
                 isbst(root->left, l, root->val) && isbst(root->right,root->val,r));
    }
    
    bool isValidBST(TreeNode* root) {
        long l=LONG_MIN, r = LONG_MAX;
        //if(root->data)
            
        return isbst(root,l,r);
    }
};