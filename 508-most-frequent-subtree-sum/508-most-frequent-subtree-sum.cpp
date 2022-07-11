class Solution {
public:
    int maxi=0;
    int  solve(TreeNode *root, unordered_map<int,int>&mp)
    {
        if(root==NULL) return 0;
        int sum = root->val + solve(root->left,mp) + solve(root->right,mp);
        mp[sum]++;
        maxi=max(maxi,mp[sum]);
        return sum;
    }
   
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int>v;
        unordered_map<int,int>mp;
        solve(root,mp);
        for(auto x:mp)
            if(x.second==maxi)
                v.push_back(x.first);
        return v;
        
    }
};