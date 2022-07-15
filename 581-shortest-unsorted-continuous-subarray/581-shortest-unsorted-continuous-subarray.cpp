class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>ans;
        for(auto &x:nums)   ans.push_back(x);
        int l=0,r=nums.size()-1;
        sort(ans.begin(),ans.end());
        
        while(l<=r)
        {
            cout<<l<<" "<<r<<endl;
            if(ans[l]==nums[l]) l++;
            else if(ans[r]==nums[r])    r--;
            else
                return r-l+1;
            
        }
        return 0;
    }
};
