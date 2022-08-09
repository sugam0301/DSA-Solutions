class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0];
        int imin = nums[0];
        int imax = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] < 0)
                swap(imin,imax);
            imin = min(nums[i]*imin, nums[i]);
            imax = max(nums[i]*imax, nums[i]);
            
            maxprod = max(imax,maxprod);
        }
        return maxprod;
    }
};