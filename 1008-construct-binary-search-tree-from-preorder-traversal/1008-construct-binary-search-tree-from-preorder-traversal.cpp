class Solution {
public:
    int preindex=0;
    TreeNode *solve(vector<int>& preorder, int l, int r)
    {
        if(l>r) return NULL;
        
        TreeNode *root = new TreeNode(preorder[preindex]);
        preindex++;
        
        int i = 0;
        for(i = l + 1; i <= r; i++)
        {
            if(preorder[i] > root->val)
                break;
        }
            
        root->left = solve(preorder, l + 1, i - 1);
        root->right = solve(preorder, i , r);
            
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};