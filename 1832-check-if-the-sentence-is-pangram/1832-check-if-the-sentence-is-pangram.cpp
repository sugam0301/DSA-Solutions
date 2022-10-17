class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mp;
        for(auto x : sentence)  
            mp[x]++;
        return mp.size()==26;
    }
};