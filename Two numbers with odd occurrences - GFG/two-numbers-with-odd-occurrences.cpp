//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long int xorr = 0;
        for(int i=0; i<n; i++)
            xorr = xorr^arr[i];
        
        int pos = 0, i;
        for(i=0;i<32;i++)
        {
            if(xorr & (1<<i))
                break;
        }
        
        pos = i;
        
        long long int b1 = 0, b2 = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] & (1<<pos))
                b1 ^= arr[i];
            else
                b2 ^= arr[i];   
        }
        
        if(b1 > b2)
            return {b1,b2};
        return {b2,b1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends