//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    stack<int>s;
    s.push(arr[n-1]);
    
    vector<int>v;
    v.push_back(0);
    
    for(int i=n-2;i>=0;i--)
    {
        while(s.size() and s.top() <= arr[i])
            s.pop();
            
        int t = s.size() ? s.top() : 0;
        v.push_back(t);
        s.push(arr[i]);
    }
    
    
    
    
    
    int total = 0;
    for(int i=0;i<n;i++)
    {
        total+=v[i];
    }
    
    return total;
}