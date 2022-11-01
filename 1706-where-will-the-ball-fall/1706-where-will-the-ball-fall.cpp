class Solution {
public:
    bool  isvalid(int r,int c,int m,int n) 
    {
        if(r>=m || r<0 || c>=n || c<0) 
            return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& grid,int row,int col , int m,int n) {
        if(row == m) 
            return col;
        if(isvalid(row,col,m,n))
        {
            if(grid[row][col]==1) {
                if(isvalid(row,col+1,m,n) && grid[row][col+1]==1)  
                {
                    return dfs(grid,row+1,col+1,m,n);
                }
            }
            else {
                if(isvalid(row,col-1,m,n) && grid[row][col-1]==-1) 
                {
                    return dfs(grid,row+1,col-1,m,n);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result (n,1);
            for(int j=0;j<n;j++) {
                result[j] = dfs(grid,0,j,m,n);
        }
        return result;
    }
};