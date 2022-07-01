static bool cmp(int &a, int &b){    return a>b;   }
class Solution {
    int f(vector<int>&v, int n, int time, vector<vector<int>>&dp)
    {
        if(n==0)    return 0;
        if(dp[n][time]!=-1) 
            return dp[n][time];
        
        //either pick the dish or not...if yes time is also incremented
        int notpick = f(v,n-1,time,dp);
        int pick = v[n-1]*time + f(v,n-1,time+1,dp);
        
        //0 is added to it so that we dont return negative values
        return dp[n][time] = max({0,pick,notpick});
    }
    
public:
    int maxSatisfaction(vector<int>& a) {
        sort(a.begin(),a.end(),cmp);
        /*reverse order is necessary 
        bcz to maximise we need the max
        to be multiplied to the  timer 
        first  to get the max sum */
        
        vector<vector<int>>dp(501, vector<int>(501,-1));
        return f(a,a.size(),1,dp);
        //initialise the timer with 1
        
    }
};