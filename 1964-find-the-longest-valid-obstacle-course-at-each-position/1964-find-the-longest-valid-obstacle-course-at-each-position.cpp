class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>v(n, 1);
        
        v[0] = 1;
        vector<int>seq;
        seq.push_back(arr[0]);
        for(int i=1;i<n;i++)
        {
            
            if(arr[i] >= seq.back())
            {
                seq.push_back(arr[i]);
                v[i] = seq.size() ;
            }
            else
            {
                int idx = upper_bound(seq.begin(),seq.end(),arr[i])- seq.begin();
                seq[idx] = arr[i];
                v[i] = idx+1;
            }
        }
        
        
        return v;
    }
};