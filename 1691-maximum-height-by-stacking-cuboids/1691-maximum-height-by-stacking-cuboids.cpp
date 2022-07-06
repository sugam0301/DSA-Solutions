class Solution {
public:
    int maxHeight(vector<vector<int>>& boxdim) 
    {
        int n = boxdim.size();
        for(auto &x : boxdim)
            sort(x.begin(), x.end());
        
        sort(boxdim.begin(), boxdim.end());
        
        //apply the MISS
        
        //init the dp 1d vector - height - MISS
        vector<int>dp(n);
       
        int res =  0;
        for(int i=0; i<n; i++)
        {
            dp[i] = boxdim[i][2];
            for(int j=0; j<i; j++)
            {
                if(boxdim[i][0]>=boxdim[j][0] and boxdim[i][1]>=boxdim[j][1] and boxdim[i][2]>=boxdim[j][2])
                dp[i] = max(dp[i], dp[j]+boxdim[i][2]);
            }
            cout<<res<<" ";
            res = max(res, dp[i]);
        }
        

        return res;
        
    }
};