class Solution {
public:
    string solve(TreeNode *root, int &vaccines)
    {
        if(!root)   return "ok";
        string l = solve(root->left, vaccines);
        string r = solve(root->right, vaccines);
        
        if(l=="want" || r=="want")
        {  vaccines++; return "provide";}
        else if(l=="provide" or r=="provide")
            return "ok";
        return "want";
        
    }
    
    int minCameraCover(TreeNode* root) {
        int vaccines = 0;
        if(solve(root,vaccines)=="want")
            vaccines++;
        return vaccines;
    }
};