#include <bits/stdc++.h>



class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s;
        int res = 0;int n=nums.size();
 
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);
 
        for (int i = 0; i < n; i++) 
        {
            if (s.find(nums[i] - 1) == s.end()) 
            {
                int curr = 1;
                while (s.find(nums[i]+curr) != s.end())
                    curr++;
     
                res = max(res, curr);
            }
        }
        return res;
    }
};



/*

Brute: Not possible in O(n^2) because they are not in the same order

Other solution: we can sort....0,1,2,3,4,5,6,7,8
if arr[i+1]==1+arr[i] is true....do count++ else 1

example: 2,4,7,9
we have  1,1,1,1




Better :


In this we have to find the longest consecutive subseq

unordered_set :  3,4,2,1,6,7,8,0,5


1. we encountered 3 first let say -> x
2. so we check if it is the start of the subseq -> x-1
3. If not, it is the start of the subseq else we have another possibility
4. 2 can be a probable start
5. No, then we check for 1...yes its present
6. now check for 0,......yes present
7. Now simply go for the next element
8. if yes, do count++ and check for another number which is conecutive


Approach:
1. Insert into the unordered_set
2. Check if it is first in the subseq....by doing s.find(x-1)==s.end()
    then do count++ and check for next element .
    
    



*/