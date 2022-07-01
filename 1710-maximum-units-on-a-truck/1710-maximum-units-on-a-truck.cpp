class Solution {

public:
    static bool mycmp(vector<int>&a, vector<int>&b)
    {
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& box, int trucksize) 
    {
        sort(box.begin(),box.end(), mycmp);
        int cnt=0;
        for(int i=0;i<box.size();i++)
        {
            int numofboxes = box[i][0];
            int unitsperbox = box[i][1];
            
            if(numofboxes < trucksize)
            {
                cnt+=numofboxes*unitsperbox;
                trucksize = trucksize - numofboxes;
            }
            else
            {
                cnt+=trucksize*unitsperbox;
                trucksize = 0;
            } 
        }
        return cnt;
    }
};