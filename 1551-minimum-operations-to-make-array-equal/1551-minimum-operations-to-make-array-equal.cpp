class Solution {
public:
    int minOperations(int n) 
    {
        int avg;
        if(n&1)
            avg= n;
        else
            avg=(n+n-1)/2;
        
        
        int ops = 0;
        for(int i=0; i<n; i++) {
            int curr = (2*i) + 1;
            ops += abs(avg-curr);
        }
        return ops/2;
    }
        
};