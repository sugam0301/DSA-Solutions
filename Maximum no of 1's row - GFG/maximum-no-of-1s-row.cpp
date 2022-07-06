// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int count(vector<int>&arr)
    {
        int n = arr.size();
        int res=-1;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid= start+(end-start)/2;
            if(arr[mid]==1)
            {
                res=mid;
                end=mid-1;
            }
            else if(arr[mid]<1)
            {
                start=mid+1;
            }

        }
        if(res==-1) return 0;
        else    return n-res;
    }
    public:
        int maxOnes (vector <vector <int>> &mat, int N, int M)
        {
            int cnt=0, res=0;
            for(int i=N-1;i>=0;i--)
            {
                int num_1s = count(mat[i]);
                // cout<<num_1s<<" ";
                cnt = max(cnt,num_1s);
                if(cnt==num_1s)
                    res = i;
            }
            return res;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends