class Solution {
public:
    bool solve(string &a,string &b,string &c,int na,int nb,int nc,
                        int i,int j,int k,vector<vector<int>>&dp)
    {
        if(i==na and j==nb and k==nc)
            return 1;
        if(i==na and j==nb and k!=nc)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool ans1=0,ans2=0;
        if(i<na and a[i]==c[k])
            ans1 = solve(a,b,c,na,nb,nc,i+1,j,k+1,dp);
        if(j<nb and b[j]==c[k])
            ans2 = solve(a,b,c,na,nb,nc,i,j+1,k+1,dp);
        
        return dp[i][j] = ans1 or ans2;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        string a=s1,b=s2,c=s3;
        int na=a.size();
        int nb=b.size();
        int nc=c.size();
        
        vector<vector<int>>dp(na+1,(vector<int>(nb+1,-1))) ;       
        return solve(a,b,c,na,nb,nc,0,0,0,dp);
    }
};
