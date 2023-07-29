//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool pal(int num)
    {
        string s = to_string(num);
        int l = 0, h = s.size()-1;
        while(l<h)
    	{
    	    if(s[l]!=s[h])
    	        return false;
    	    l++, h--;
    	}
        return true;
    }

    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++)
    	{
    	    if(!pal(a[i]))
    	        return 0;
    	}
    	
    	return 1;
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends