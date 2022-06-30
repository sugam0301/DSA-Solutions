class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        //we ll start by dividing the array into 2halves
        //for this we cut the arrays in this way that it is :
        //if even, n1+n2+1 whole divided by 2
        //if odd , then also same as above
        //l2<=r2 and l1<=r1
        int n1=nums1.size(), n2=nums2.size();
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        
        int low=0,high=n1;
        while(low<=high)
        {
            int cut1 = (low+high)>>1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int l1 = (cut1==0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2==0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1==n1)?INT_MAX:nums1[cut1];
            int r2 = (cut2==n2)?INT_MAX:nums2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                    return (max(l1,l2) + min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
            
        }
        
        return 0.0;
        
    }
};