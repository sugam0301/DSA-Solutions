//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 private:
    long long mod = 1e9+7;
    long long dp[100][100];
    long long f(int m ,int n)
    {
        if(n==0 || m==0)    return 1; 
        if(dp[m][n]!=-1)    return dp[m][n];
        return dp[m][n]=(1ll*f(m-1,n) + 1ll*f(m,n-1))%mod;
    }
public:
    long long int numberOfPaths(int m, int n){
        memset(dp,-1,sizeof(dp));
        return f(m-1,n-1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends