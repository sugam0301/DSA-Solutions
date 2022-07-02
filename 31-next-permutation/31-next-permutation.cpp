class Solution {
public:
    void nextPermutation(vector<int>& arr) 
    {
        int n=arr.size();
        int ind1 = -1;
        for(int i=0;i<n-1;i++)
            if(arr[i]<arr[i+1]) ind1 = i;

        if(ind1 == -1)
        {
           reverse(arr.begin(),arr.end());
            return;
        }
                
        int ind2 = -1;
        for(int i=ind1+1;i<n;i++)
            if(arr[i]>arr[ind1]) ind2 = i;
        
        swap(arr[ind1], arr[ind2]);
        reverse(arr.begin() + ind1 + 1, arr.end());   
    }
};