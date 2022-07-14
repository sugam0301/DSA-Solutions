// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        long long int num1 = 0,num2 = 0,temp=1;
        sort(arr,arr+n);
        for(int i=n-1;i>=0;i-=2)
        {
            num1+=arr[i]*temp;
            temp*=10;
        }
        temp = 1;
        for(int i=n-2;i>=0;i-=2)
        {
            num2+=arr[i]*temp;
            temp*=10;
        }
        return num1+num2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends