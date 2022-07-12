class Solution {
public:
    int di[4] = {0,-1,1,0};
    int dj[4] = {1,0,0,-1};
    long long int mod = 1e9 + 7;
    int dfs(vector<vector<int>>&grid, int i,int j,int n, int m, int parent,vector <vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int cnt=1;
        for(int ind=0;ind<4;ind++)
        {
            int newi = i + di[ind];
            int newj = j + dj[ind];
            if(newi>=0 and newj>=0 and newi<n and newj<m and grid[newi][newj] > parent)
                cnt = (cnt%mod + dfs(grid,newi,newj,n,m,grid[newi][newj], dp)%mod)%mod;
        }
        return dp[i][j] =  cnt%mod;
    }
    
    
    int countPaths(vector<vector<int>>& grid) 
    {
        vector <vector <int>> dp(grid.size(),vector<int>(grid[0].size(),-1));

        int n = grid.size();
        int m = grid[0].size();
        long long int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                 res= (res%mod + dfs(grid,i,j,n,m,grid[i][j],dp)%mod)%mod;
        }
        return res%mod;
    }
};