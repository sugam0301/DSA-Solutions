class Solution {
public:
    double calc(int n,int k,int r,int c,vector<vector<vector<double>>>& dp, vector<int>& drxn)
    {
        if(k==0)
            return dp[r][c][k]=1;
        double ans=0;
        if(dp[r][c][k]!=0)
            return dp[r][c][k];
        for(int i=0;i<8;i++)
        {
            int row=r+drxn[i];
            int col=c+drxn[i+1];
            if(row>=0 && row<n && col>=0 && col<n)
                ans+=calc(n,k-1,row,col,dp,drxn)/8.0;
        }
        return dp[r][c][k]=ans;
    }
    double knightProbability(int N, int K, int r, int c) 
    {
        double prob=0;
        vector<int> drxn{2,1,2,-1,-2,1,-2,-1,2};
        vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(K+1)));
        calc(N,K,r,c,dp,drxn);
        return dp[r][c][K];
    }
};