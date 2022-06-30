class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        
        int low,high;
        for(int i=0;i<n;i++)
        {   
            low=i+1,high=n-1;
            int sum = -nums[i];
            while(low<high)
            {
                //if greater than sum to ham left jaynge
                if(nums[low] + nums[high]>sum) 
                    high--;
                //otherwise rightside
                else if(nums[low] + nums[high]<sum)
                    low++;
                else
                {
                    res.push_back({ nums[i], nums[low], nums[high] });
                    //to avoid any repetition we do low++ and high-- rest is simple
                    while(low<high && nums[low]==nums[low+1])      low++;
                    while(low<high && nums[high]==nums[high-1])    high--;
                    low++;high--;
                }
            }
            
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
        
    }
};