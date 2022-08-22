class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int m=(int)grid.size();
        int n=(int)grid[0].size();
        int i=m-1;
        int j=0;
        
        int cnt=0;
        while(i>=0 && j<n)
        {
            if(grid[i][j]<0)
            {
                cnt+=n-j;
                i--;    
            }
            else
                j++;    
        }
        return cnt;
    }
};