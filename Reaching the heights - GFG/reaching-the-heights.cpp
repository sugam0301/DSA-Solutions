// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) 
{
    sort(a,a+n);
    vector<int>v;
    int low = 0, high=n-1;
    while(low<high)
    {
        v.push_back(a[high]);
        v.push_back(a[low]);
        low++;high--;
    }
    if(low==high)
        v.push_back(a[low]);
    
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(i&1)     sum-=v[i];
        else        sum+=v[i];
    }
    if(sum<=0)  return {-1};
        
    return v;
        
}
