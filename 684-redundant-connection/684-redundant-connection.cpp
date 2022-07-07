class Solution {
private:
    bool unionn(int u, int v, vector<int> &parent, vector<int> &rank) 
    {
        int p1 = findPar(u, parent);
        int p2 = findPar(v, parent);
        
        if(rank[p1] < rank[p2]) 
            parent[p1] = p2;
        
        else if(rank[p2] < rank[p1])
            parent[p2] = p1; 
        else 
            parent[p2] = p1;
            rank[p1]++; 
        
        if(p1==p2)  
            return false;
        return true;
    }
    
    
    int findPar(int u, vector<int> &parent) 
    {
        if(u == parent[u]) 
            return u; 
        return parent[u] = findPar(parent[u], parent); 
    }
    
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int N = edges.size();
        
        vector<int> parent(N+1,0);
	    for(int i = 0;i<N+1;i++) 
	        parent[i] = i;
        
	    vector<int> rank(N+1, 0); 
        
        vector<int>v;
        for(auto e:edges)
            if(!unionn(e[0],e[1],parent,rank))
                // return e;
                v={e[0],e[1]};
        return v;    
    }
};