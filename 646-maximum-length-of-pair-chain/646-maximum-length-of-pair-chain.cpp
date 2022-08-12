class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n=pairs.size();
        if(n==1) return 1;
        sort(pairs.begin(),pairs.end());
        vector<int> dp(n,1);
        
        int mx=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1] < pairs[i][0])
                    dp[i]=max(dp[i],dp[j]+1);
            }  
            mx = max(dp[i], mx);
        }
        return mx;
    }
};