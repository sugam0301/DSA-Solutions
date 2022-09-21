class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int idx1 = -1, idx2 = -1;
        int n= nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1] > nums[i])
                idx1 = i;
        }
        
        if(idx1 == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=idx1+1;i<n;i++)
        {
            if(nums[idx1] < nums[i])
                idx2 = i;
        }
        
        swap(nums[idx1], nums[idx2]);
        
        reverse(nums.begin() + idx1 + 1, nums.end());
        
        
    }
};