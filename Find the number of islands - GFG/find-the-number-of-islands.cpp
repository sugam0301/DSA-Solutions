//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        static int di[8]={-1,0,1,0,-1,1,-1,1};
        static int dj[8]={0,1,0,-1,-1,1,1,-1};
        grid[i][j]='0';
        
        for(int ind=0;ind<8;ind++)
        {
            int newx=i+di[ind];
            int newy=j+dj[ind];
            
            if(newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy]=='1')
                dfs(grid,newx,newy,n,m);   
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends