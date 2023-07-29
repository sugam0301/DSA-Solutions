//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        unordered_map<char, int>mp;
        char c='#';
        
        for(char x: s)    mp[x]++;
        
        for(int i=0;i<s.size();i++)
        {
            if(mp[s[i]] > 1)
            {    c = s[i]; break;}
        }
        
        
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends