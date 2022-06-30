class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // vector<int>v;
        unordered_set<int>s; 
        int i,j,c;
        for(i=0;i<nums.size();i++)
        {
            if(s.find(target-nums[i])!=s.end())
            {
                c=target-nums[i];
                break;
            }   
            
            s.insert(nums[i]);
        }
        for(j=0;j<nums.size();j++)
        {
            if(c==nums[j])
                break;
        }
        return {j,i};
    }
};