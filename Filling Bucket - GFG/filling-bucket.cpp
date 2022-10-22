//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = 1e8;
  public:
    int fillingBucket(int n) 
    {
        if(n==1)     return 1;
        int f = 1, s = 2, t;
        for(int i=2;i<n;i++)
            t=(s+f)%mod,
            f = s,
            s = t;
            
        return t%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends