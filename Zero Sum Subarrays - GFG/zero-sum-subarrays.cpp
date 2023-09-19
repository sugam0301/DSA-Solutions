//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        int res = 0;
        
        unordered_map<int,int> mp;
        int presum = 0;
        
        for(int i = 0;i<n;i++)
        {
            presum+=arr[i];
            if(presum==0)
                res++;
            if(mp.find(presum)!=mp.end())
                res+=mp[presum];
            mp[presum]++;    
            
        }
        
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends