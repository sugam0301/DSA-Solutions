class Solution {
public:
    bool isPowerOfThree(int n) {
        // M-1 sum of digits is 3
        if(n==0)    return false;
        // int sum=0;
        // while(n)
        // {
        //     sum+=n%10;
        //     n = n/10;
        // }
        // return sum%3==0;
        
        
        
         // M-2  3^19 =1162261467, 
	     //  3^20 is exceding  Integer_Range So 3^19 is the highest power in Integer Range  
         return ( n>0 &&  1162261467%n==0);
        
        

    }
};