class Solution {
public:
    int maxArea(vector<int>&a) 
    {
        int water = 0; int n=a.size();
        int i = 0, j = n-1;
        while(j>i)
        {
            int h = min(a[i],a[j]);
            water = max(water, (j-i)*h);
            
            if(a[i]<=h)  i++;
            if(a[j]<=h)  j--;
        }
        return water;        
    }
};