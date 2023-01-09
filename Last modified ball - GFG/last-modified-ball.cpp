//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n, vector<int> arr) {
        reverse(arr.begin(), arr.end());
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int val = arr[i];
            if(val + 1 > 9 and i+1<n)
            {
                arr[i+1] += 1;
            }
            else
            {
                res =  i;
                break;
            }
        }
        return n - res ;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends