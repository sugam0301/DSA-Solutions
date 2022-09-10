class Solution {
public:
    int dp[1001][201];
    int solve(vector<int>& prices,int days, int transleft,int k)
    {
        int ans,ans1=0,ans2=0;
        
        if(days >= prices.size()){
            return 0;
        }
        
        if(transleft == 0){
            return 0;
        }
        if(dp[days][transleft]!=-1)
            return dp[days][transleft];
        
        //choice 1
        //no trans
        ans1 = solve(prices,days+1,transleft,k);
        
        //choice2 
        int buy = (transleft%2==0)?1:0;
        if(buy==1)
            ans2 = -prices[days] + solve(prices,days+1,transleft-1,k);
        else
            ans2 = prices[days] + solve(prices,days+1,transleft-1,k);
        
        return dp[days][transleft] = max(ans1,ans2);
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
         //1.at most k+k buys and sells
        //2. max k - b1,s1,b2,s2,b3,s3,.......
        //3. we have days as prices.size() and also we have 4 transleft - k*b,k*s
        //4. we can also do that if a stock is bought then we have to sell to buy again
        //5. we have transleft = k*2, days = prices.size(), buy = true;
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,2*k,k);
    }
};