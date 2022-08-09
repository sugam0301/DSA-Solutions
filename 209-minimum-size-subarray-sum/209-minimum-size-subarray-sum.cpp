class Solution {
public:
    int minSubArrayLen(int k, vector<int>& arr) {
        int n = arr.size();
        
        int i = 0, j=0, sum = 0;
        int res=INT_MAX;
        while(j<n)
        {
            sum+=arr[j];
            
            while(sum>=k)
            {
                res = min(res, j-i+1);
                sum-=arr[i];
                i++;
            }   
            j++;
        }
        return res==INT_MAX ? 0 : res;
    }
};