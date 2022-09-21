class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) 
    {
        int s = 0;
        for (auto &x:a)    if (x%2==0)     s += x;
        
        vector<int> ans;
        for (auto &x:q) 
        {
            int val = x[0],  idx = x[1];
            if (a[idx] % 2 == 0)     s -= a[idx];
            
            a[idx] += val;
            if (a[idx] % 2 == 0)     s += a[idx];
            
            ans.push_back(s);
        }
        return ans;
    }
};