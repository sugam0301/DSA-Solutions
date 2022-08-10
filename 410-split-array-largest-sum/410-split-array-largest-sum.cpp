class Solution {
private:
    bool ispossible(vector<int>&arr, int barrier, int m)
    {
        int sum = 0;
        int count = 1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] > barrier)    return false;
            
            if(sum + arr[i] > barrier)
            {
                sum = arr[i];
                count++;
            }
            else
                sum+=arr[i];
        }
        
        return count<=m;
    }
    
public:
    int splitArray(vector<int>& arr, int m) 
    {
        int n = arr.size();
        int low = 0, high = 0;
        for(auto x:arr)     high+= x;
        
        int res=0;
        
        while(low <= high)
        {
            int mid = (low+high)>>1;
            
            if(ispossible(arr, mid, m))
            {
                res = mid;
                high = mid-1;
            }
            
            else
                low = mid+1;
        }
        
        return res;
    }
};