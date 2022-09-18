import math
class Solution:
    def trap(self, a: List[int]) -> int:
        n = len(a)
        l = [0]*n
        r = [0]*n
        
        l[0] = a[0]
        for i in range(1, n):
            l[i] = max(l[i-1], a[i])
        
        r[n-1] = a[n-1]
        for i in range(n-2,-1,-1):
            r[i] = max(r[i+1], a[i])
        
        # print(l, r)
        s = 0
        for i in range(n):
            s= s + min(l[i],r[i])-a[i]
            
        return s
            
        