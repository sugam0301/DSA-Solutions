//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
    int lrs(string &a, string &b, int n, int m, vector<vector<int>>&dp)
    {
        if(n==0 || m==0)    return 0;
        
        if(dp[n][m]!=-1)    return dp[n][m];
        
        if(n!=m and a[n-1]==b[m-1])
            return dp[n][m] = 1+ lrs(a,b,n-1,m-1,dp);
        return dp[n][m] =  max( lrs(a,b,n-1,m,dp), lrs(a,b,n,m-1,dp));
            
    }
    
    
    
	public:
		int LongestRepeatingSubsequence(string str){
		    string s = str;
		    int n = s.size();
		    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
		    return lrs(s, s, n, n, dp);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends