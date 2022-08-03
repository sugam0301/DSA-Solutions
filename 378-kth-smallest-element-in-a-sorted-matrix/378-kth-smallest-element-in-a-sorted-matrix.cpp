class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
		int low= matrix[0][0], high= matrix[n - 1][n - 1];
		int mid = 0;int res=0;
		while (low <=high)
		{
			mid = (low + high)/2;
			int num = 0;
            for(int i=0;i<n;i++)
                num+=upper_bound(matrix[i].begin(),matrix[i].end(), mid) - matrix[i].begin();
            
            if(num < k)
                low=mid+1;
            else
            {
                res = mid;
                high = mid-1;
            }
            
        }
        return res;
            
            
    }
};