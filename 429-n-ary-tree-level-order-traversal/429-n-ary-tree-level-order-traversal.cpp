class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        
        if(!root)   return {}; //base case 
        
        queue<Node *>q;
        q.push(root);
        
        while(q.size())
        {
            int cnt = q.size();
            vector<int>v;
            for(int i=0;i<cnt;i++)
            {
                Node *curr = q.front(); q.pop();
                
                v.push_back(curr->val);
                
                for(auto &x: curr->children) //a diff line - as we do in graph rest same
                    
                    q.push(x);
            }
            res.push_back(v);
        }
        
        
        return res;
    }
};