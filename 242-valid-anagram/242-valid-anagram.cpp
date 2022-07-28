class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:s)   mp[x]++;
        for(auto x:t)  { mp[x]--; if(mp[x]==0)  mp.erase(x);}
        return !(mp.size());
    }
};