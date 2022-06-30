class Solution 
{
public:
    string longestPalindrome(string s)
    {
        string res="";
        int maxlen = 0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            int l=i, r=i;
            while(l>=0 and r<n and s[l]==s[r])
            {
                if(maxlen<r-l+1)
                {
                    maxlen = r-l+1;
                    res = s.substr(l,r-l+1);
                }
                 l--;
                 r++;
            }
           
        }
        for(int i=0; i<n; i++)
        {
            int l=i, r=i+1;
            while(l>=0 and r<n and s[l]==s[r])
            {
                if(maxlen<r-l+1)
                {
                    maxlen = r-l+1;
                    res = s.substr(l,r-l+1);
                }
                l--;                
                r++;
            }
        }
        return res;
    }
};