#define pb push_back
class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
      return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& a) 
    {
        sort(a.begin(),a.end(),compare);
        int n = a.size();
        vector<int>seq;
        
        seq.pb(a[0][1]); //first height - h0
        
        for(int i=1;i<n;i++)
        {
            int val = a[i][1];
            if(val > seq.back())
                seq.pb(val);
            else
            {
                //lower_bound bcz it will lead to idx of element >= ...
                //we can replace that and get the longest subseq
                //but equal to so as to increase the length as more as possible
                int idx = lower_bound(seq.begin(), seq.end(), val) - seq.begin();
                seq[idx] = val;
            }
        }
        return seq.size();
    }
    
};