class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        int res=0;
        
        while (lo <= hi) 
        {
            int mid = lo + (hi - lo) / 2;
            if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))
                return mid;
            
            if(mid==n-1 || arr[mid]>arr[mid+1])
                hi = mid-1;
            else
                lo = mid+1;
                
        }
        return -1;   
    }
};