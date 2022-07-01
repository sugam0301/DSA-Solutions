class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) //rotations
            sort(cuboids[i].begin(), cuboids[i].end());
        
        sort(cuboids.begin(), cuboids.end());
        //Max Sum Inc Subseq 
        for(int i = 0; i < n; i++) 
        {
            dp[i] = cuboids[i][2]; 
            for(int j = i - 1; j >= 0; j--) 
            {
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && 
                   cuboids[i][2] >= cuboids[j][2]) 
                    dp[i] = max(dp[i], cuboids[i][2] + dp[j]);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};