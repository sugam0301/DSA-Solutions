class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int dist[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = (i==j) ? 0 : 10000000;
        
        for(int i=0;i<n;i++)
            dist[i][i] = 0;
        
        for(auto &v : edges)
        {
            dist[v[0]][v[1]] = v[2];
            dist[v[1]][v[0]] = v[2];
        }
    
        for(int k = 0;k < n;k++)
            for(int i = 0;i < n;i++)
                for(int j = 0;j < n;j++)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        
        int res = -1;
        int min_count = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
                if(dist[i][j] <= distanceThreshold)
                    count++;
            //Return the city with the smallest number of cities that are 
            //reachable through some path and whose 
            //distance is at most the Threshold 
            
            
            //we do count==min_count also because we need largest city
            //from where the least number of cities are reachable with threshold 
            if(count <= min_count)
            {
                min_count = count;
                res = i;
            }
        }
        return res;
        
    }
};