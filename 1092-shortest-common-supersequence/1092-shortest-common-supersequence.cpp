class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int m=str1.size();
        int n=str2.size();
        
        int dp[m+1][n+1];                //Initialisation of DP size
      
        for(int i=0;i<=m;i++)          //LCS DP Table
        {
            for(int j=0;j<=n;j++)
            { 
                if(i==0 || j==0)         //Base condition if size of any string is 0,then answer is 0
                    dp[i][j]=0;
                else if(str1[i-1]==str2[j-1]) 
                {
                    //if str is equal then we increase the answer by one otherwise max of any of the subproblem either moving the pointer of s1 or s2 and then finding the maximum
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                    dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        //cout<<dp[m][n];
        
        string res;
        int i=m,j=n;         //now we have the length of the dp SCS at the dp[m][n] ,right? so we move from bottom right because in recursion what we do is we move from the bigger problem and then we decrease the input till the smallest valid input.
        
        while(i>0 && j>0)
        {         //we' ll traverse the matrix with the 2pointer approach till any of the index gets 0 bcz at 0 index in the dp table we have NULL string so we wont get anything so condition will be i>0 and j>0
        
            
        //if both the characters are equal then we move diagonally top and also push the character into the result
            if(str1[i-1]==str2[j-1])      
            {
                res.push_back(str1[i-1]);
                i--;j--;
                //cout<<res<<endl;
            }
            
            else 
            {
                if(dp[i-1][j]>dp[i][j-1])  //if not equal we move in the direction of the bigger no.
                {
                    res.push_back(str1[i-1]);
                    i--;
                    //cout<<res<<endl;
                }
                else{
                    res.push_back(str2[j-1]);
                    j--;
                    //cout<<res<<endl;
                }
            }
        } 
            //cout<<res;
            while(i>0)
            {
                 res.push_back(str1[i-1]);
                 i--;
                //cout<<res<<endl;
            }
            cout<<res<<endl;
            while(j>0)
            {
                 res.push_back(str2[j-1]);
                 j--;
                //cout<<res<<endl;
            }
            
        
        
        reverse(res.begin(),res.end());
        //cout<<res<<endl;
        return res;
        
        
        
    }
};