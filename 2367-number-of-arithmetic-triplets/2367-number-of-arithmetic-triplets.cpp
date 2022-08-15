class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int cnt = 0;
        unordered_map<int,int> mp;
        for(auto x:nums)    mp[x]++ ;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]-diff] and mp[nums[i]+diff])
                cnt++;
        }        
        return cnt;
    }
};