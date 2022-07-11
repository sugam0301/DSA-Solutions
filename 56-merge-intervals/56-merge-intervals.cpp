typedef vector<vector<int>> vii;
class Solution {
public:
    vii merge(vii & arr) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(n<=1)   return arr;
        vii res;
        
        res.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            if(arr[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1],arr[i][1]);
            else
                res.push_back(arr[i]);
        }
        return res;
    }
};