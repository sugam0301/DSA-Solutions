#define vii vector<vector<vector<int>>>
#define vi vector<vector<int>>
class Solution {
public: 
   int mx=1e9+7;
   vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

   int find(int m, int n, int moves, int i, int j,vii &dp)
   { 
       if(i<0||j<0||i>=m||j>=n) 
           return 1; 
       if(moves==0) 
           return 0;
       
       if(dp[moves][i][j]!=-1) 
           return dp[moves][i][j];
       
       int res=0; 
       
       for(auto x:dir) 
       {
           res+=find(m,n,moves-1,i+x[0],j+x[1],dp); 
           res%=mx;
       }
       return dp[moves][i][j]=res%mx; 
   }
   
   int findPaths(int m, int n, int N, int i, int j) {
       vii dp(N+1,vi (m,vector<int>(n,-1)));
       return find(m,n,N,i,j,dp);
   }
};