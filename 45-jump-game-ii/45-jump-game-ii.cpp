class Solution {
public:
    int solve(vector<int> &nums , int curr, int dest,vector<int> &dp)
    {       
        if(curr>=dest) return 0; 
        int tmp=nums.size();
		
     //Try Every jump 1 to nums[curr] jump & find minimum steps need to reach end
		if(dp[curr]!=-1) return dp[curr];
        for(int i=1;i<=nums[curr];i++)
            tmp=min(tmp,1+solve(nums,curr+i,dest,dp));  

        return dp[curr]=tmp;
    }
    
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,nums.size()-1,dp);   
    }
};