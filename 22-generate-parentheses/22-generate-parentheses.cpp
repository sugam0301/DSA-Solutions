class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string curr= "";
        addingpar(res, curr, n, n);
        return res;
    }
    void addingpar(vector<string> &v, string &curr, int n, int m){
        if(n==0 && m==0) 
        {
            v.push_back(curr);
            return;
        }
        if(n > 0)
        { 
            curr.push_back('(');
            addingpar(v,curr, n-1, m); 
            curr.pop_back();
        }
        if(m > n)
        { 
            curr.push_back(')');
            addingpar(v, curr, n, m-1); 
            curr.pop_back();
        }
    }           
    
};