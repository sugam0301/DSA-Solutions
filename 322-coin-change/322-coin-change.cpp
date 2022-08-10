class Solution {
public:
    int dp[10000 + 1][12 + 1];
    
    int f(vector<int>& coins, int w, int n)
    {
        if(w==0)    return 0;
        if(n==0)    return INT_MAX - 1;
        
        if(n==0 and w==0)   return 0;
        
        if(dp[w][n] != -1)
            return dp[w][n];
        
        
        if(coins[n-1] <= w)
            return dp[w][n] = min(f(coins, w-coins[n-1],n) + 1,  f(coins, w, n-1));
        return dp[w][n] =  f(coins, w, n-1);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int ans =  f(coins, amount, coins.size());
        if(ans==INT_MAX-1)
            return -1;
        else
            return ans;
    }
};