#define ss set<string>
class Solution {
public:
    bool wordBreak(string s, vector<string>& d) 
    {
        ss dict(d.begin(), d.end());
        vector<int>dp(s.size(), -1);
        return f(0, s, dict, s.size(), dp);
    }
	
	bool f(int ind, string &s, ss &dict, int n, vector<int>&dp) 
    {
        if(ind == n) return true;
        
        if(dp[ind]!=-1) return dp[ind];
        
        for(int i = ind; i < n; i++) 
        {
            string cur = s.substr(ind, i-ind+1);
            if(dict.count(cur) && f(i+1, s, dict, n, dp)) 
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }
};