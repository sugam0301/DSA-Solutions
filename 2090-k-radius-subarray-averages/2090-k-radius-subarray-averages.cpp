class Solution {
public:
vector<int> getAverages(vector<int>& nums, int k) 
{
    int n = nums.size();
	vector<long long> prefSum(n, 0);

	for(int i=0; i<n; i++)
		prefSum[i] = nums[i] + ((i==0) ? 0 : prefSum[i-1]),
        cout<<prefSum[i]<<" ";
	
    vector<int> avgs(n, -1);
    
	int d = 2*k + 1;
	for(int i=k; i<n-k; i++)
    {
        int a = (i-k-1) < 0 ? 0: prefSum[i-k-1];
        avgs[i] = (prefSum[i+k] - ((i-k-1) < 0 ? 0 : prefSum[i-k-1])) / d;
    }

	return avgs;
    }
};