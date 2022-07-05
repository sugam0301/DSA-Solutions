class Solution {
    TreeNode *lca(TreeNode *root ,int n1, int n2)
    {
        if(!root)
            return nullptr;
        if(root->val == n1 or root->val==n2)
            return root;
        
        TreeNode *left = lca(root->left, n1, n2);
        TreeNode *right = lca(root->right,n1,n2);
            
        if(left and right)
            return root;
        else if(left)
            return left;
        return right;
    }
    public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)   return nullptr;
        queue<TreeNode *>q;
        q.push(root);
        vector<TreeNode *>v;
        v.push_back(root);
        while(q.size())
        {
            int cnt=q.size();
            v.clear();
            for(int i=0;i<cnt;i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                
                v.push_back(curr);
                if(curr->left)
                {
                    // v.push_back(curr->left);
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    // v.push_back(curr->right);
                    q.push(curr->right);
                }
            }
            
        }
        cout<<v.size();
        if(v.size()==1) 
            return v[0];
        
        TreeNode *ancestor = lca(root, v[0]->val, v[1]->val);
        TreeNode *newlca;
        for(int i=2; i<v.size(); i++)
        {
            newlca = lca(root, ancestor->val, v[i]->val);
            ancestor = newlca;
        }
            
        return newlca;
    }
};