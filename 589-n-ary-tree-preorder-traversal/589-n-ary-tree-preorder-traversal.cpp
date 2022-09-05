class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) 
    {
        if(!root) return ans;         
        ans.push_back(root -> val);   
        for (auto& child : root -> children) preorder(child);  
        return ans;
    }
};