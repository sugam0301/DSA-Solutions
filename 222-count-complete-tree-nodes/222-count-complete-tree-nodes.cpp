class Solution {
public:
    int leftheight(TreeNode *root)
    {
        int h = 1;
        while(root->left)
        {
            root = root->left;
            h++;
        }
        return h;
    }
    int rightheight(TreeNode *root)
    {
        int h = 1;
        while(root->right)
        {
            root = root->right;
            h++;
        }
        return h;
    }
    
    
    int countNodes(TreeNode* root) {
        
        if(!root)   return 0;
        
        int lh = leftheight(root);
        int rh = rightheight(root);
        
        if(lh == rh)    return pow(2,lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};