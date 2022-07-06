// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        if(arr[1]!=arr[0])  return arr[0];
        if(arr[n-1]!=arr[n-2])  return arr[n-1];
        
        int l=0,r=n-1;
        while(l<=r)
        {
            int m = (l+r)>>1;
            if(arr[m]!=arr[m-1] and arr[m+1]!=arr[m])
                return arr[m];
                
            if(arr[m]!=arr[m+1])
            {
                if(m&1) l=m+1;
                else    r=m-1;
            }
            else
            {
                if(m&1) r=m-1;
                else    l=m+1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends