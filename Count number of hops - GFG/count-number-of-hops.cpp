//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long mod=1000000007;
    long long f(int n,vector<int> &dp)
    {
        if(n==0) return 0;
        if(n==1)
          return 1;
        else if(n==2)
          return 2;
        else if(n==3)
          return 4;
       if(dp[n]!=-1) return dp[n];
       int w1= f(n-1,dp);
       int w2=f(n-2,dp);
       int w3=f(n-3,dp);
       return dp[n]=(w1%mod+w2%mod+w3%mod)%mod;
   }
   
   long long countWays(int n)
   {
       vector<int> dp(n+1,-1);
       return f(n,dp);
   }
};



//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends