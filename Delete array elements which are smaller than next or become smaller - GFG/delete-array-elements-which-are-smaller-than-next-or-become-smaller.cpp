//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> deleteElement(int arr[],int n,int k);

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        vector<int> v;
        
        v = deleteElement(arr,n,k);
        vector<int>::iterator it;
         for(it=v.begin();it!=v.end();it++)
            cout<<*it<<" ";
        cout<<endl;
        
    }
return 0;
}

// } Driver Code Ends


vector<int> deleteElement(int arr[],int n,int k)
{
    vector<int> ans;
    
    for(int i = 0; i < n; ++ i) 
    {
        while (ans.size() && arr[i] > ans.back() && k) 
        {
            ans.pop_back();
            -- k;
        }
        
        ans.push_back(arr[i]);
    }
    
    return ans;
    
}
