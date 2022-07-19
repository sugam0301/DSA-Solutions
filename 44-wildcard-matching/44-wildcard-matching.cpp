class Solution {
public:
    int dp[1050][1050];
    bool solve(string &s, string &p, int n, int m)
    {
        //3base cases mainly:
        //REFER NOTES here ->
        // Lets say both char match or is there any ? then we will just                     move the pointers
        // if there is a "*",   then there can be multiple characters or no                     charachter at all
        
        // adceb
        // *a*b
        
        // in this , * - dce and first * contains the ""
        // so in case, s finished, then we should see if * is there or not
        //if no * tehn return false otherwise true
        

        //base conditions:
        //1.both s and p ended, true
        //2.p ended, then return false
        //3. s ended then we should see if p has all * or not
        
        if(n<0 && m<0)
            return true;
        if(m<0)
            return false;
        if(n<0)
        {
           for(int i=0;i<=m;i++)  if(p[i]!='*') return false;
            return true;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        bool res=false;
        if(p[m]=='*')
        {
             res |=  solve(s,p,n-1,m);
             res |=  solve(s,p,n,m-1);
        }
        else
        {
            if(s[n]==p[m] || p[m]=='?')
            return res |=  solve(s,p,n-1,m-1);
        }
        return dp[n][m]=res;
    }

    
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,p,n-1,m-1);
    }
};