class Solution {
    
private:
    unordered_map<TreeNode *, TreeNode *>mp;
    void findparent(TreeNode *root)
    {
        if(!root)   return ;
        if(root->left) mp[root->left] = root;
        if(root->right)mp[root->right]=root;
        
        findparent(root->left);
        findparent(root->right);
    }
    
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* x, int k) 
    {
        findparent(root);
        if(!root)   return {};
        if(k==0)    return {x->val};        
        unordered_set<TreeNode *>s;
        vector<int>v;
                
        queue<TreeNode *>q;
        q.push(x);
        s.insert(x);
        int level = 0;
        while(q.size())
        {
            int cnt = q.size();
            for(int i=0;i<cnt;i++)
            {
                TreeNode *curr = q.front(); 
                s.insert(curr);
                q.pop();
                
                if(curr->left && s.find(curr->left)==s.end())
                    q.push(curr->left), s.insert(curr->left);
                
                if(curr->right && s.find(curr->right)==s.end())
                    q.push(curr->right), s.insert(curr->right);
                
                if(mp[curr] && s.find(mp[curr])==s.end())
                    q.push(mp[curr]), s.insert(mp[curr]);
            }         
            level++;
            if(level==k)break;
        }
        
        while(q.size())
        {
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
        
    }
};