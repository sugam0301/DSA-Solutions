class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>&vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 or j<0 or i==m or j==n or vis[i][j]==true)   return 0;
        if(grid[i][j]==0)   return 0;
        
        vis[i][j]=true;
        return  1 + dfs(grid,i+1,j,vis) + dfs(grid,i,j+1,vis) + dfs(grid,i-1,j,vis) + dfs(grid,i,j-1,vis);
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>>vis(m, (vector<bool>(n,false)));
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    cnt=max(cnt, dfs(grid,i,j,vis));
            }
        }
        return cnt;
    }
};