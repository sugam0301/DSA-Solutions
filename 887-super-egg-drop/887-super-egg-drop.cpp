class Solution {
private:
    int dp[10001][101];
    int f(int k, int n)
    {
        if(n==1)    return k;
        if(k==0 or k==1)    return k;
        
        if(dp[k][n]!=-1)    return dp[k][n];
        
        int ans = INT_MAX;
        int low = 0, high = k;
        
        while(low<=high)
        {            
            int mid = (low + high)/2;
            
            int down = f(mid-1, n-1);
            int up = f(k-mid, n);
            
            int attempt = 1 + max(down, up);
            
            if(down<up)
                low = mid+1;
            else
                high = mid-1;
            
            ans = min(ans, attempt);
        }        
        return dp[k][n] =  ans;
    }
 
public:
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return f(n,k);
    }
};