#define p pair<string,int>
// we cant make a static bool fxn in priority_queue so we have to make a class cmp and then overload ()
class comp{
    public:
    bool operator()(p &a, p &b) const
    {
        if(a.second > b.second) return true;
        else if(a.second == b.second && a.first < b.first) return true;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> dict;
        for(string &s:words) dict[s]++;
        
        priority_queue< p, vector<p>, comp> pq;        
        for(auto &x : dict) 
        {
            pq.push({x.first, x.second});
            if(pq.size()>k) pq.pop();
            // cout<<pq.top().first<<" ";
        }    
        
        vector<string> result;
        while(!pq.empty()) 
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        // cout<<endl;
        reverse(result.begin(),result.end());    
        return result; 
    }
};