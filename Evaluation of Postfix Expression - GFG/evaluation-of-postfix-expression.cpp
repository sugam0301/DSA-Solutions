//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:

    bool isnum(char &ch)
    {
        if(ch>='0' and ch<='9')
            return true;
        return false;
    }

    bool isoperator(char &ch)
    {
        if(ch == '+' or ch=='-' or ch=='*' or ch=='/' or ch=='^')
            return true;
        return false;
    }

    void perform_op(char &ch, stack<int>&s, int b, int a)
    {
        if(ch=='+') 
            s.push(a+b);
        else if(ch=='*')
            s.push(a*b);
        else if(ch=='/')
            s.push(a/b);
        else if(ch=='-')
            s.push(a-b);
    }


public:
    int evaluatePostfix(string &str)
    {
        stack<int>s;
        for(int i=0; i<str.size();i++)
        {
            char ch = str[i];
            
            if(isnum(ch))
            {
                s.push(ch-'0');
            }
            else if(isoperator(ch))
            {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                // cout<<a<<" "<<b<<endl;
                perform_op(ch, s, a, b);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends