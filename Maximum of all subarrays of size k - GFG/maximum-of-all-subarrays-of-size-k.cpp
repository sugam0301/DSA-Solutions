//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>v;
        deque<int>dq;
        int i = 0, j = 0;
        while(j<n)
        {
            while(dq.size() > 0 and arr[j] > dq.back())    dq.pop_back();
            dq.push_back(arr[j]);
            
            if(j-i+1 < k)
                j++;
            else
            {
                if(dq.size())   v.push_back(dq.front());
                else            v.push_back(-1);
                
                //remove the ith index value
                if(dq.front() == arr[i])    dq.pop_front();
                
                //move the window
                i++;j++;
            }
        }
     
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends