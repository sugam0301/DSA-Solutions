// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    void dfs(vector<int>adj[], int n, int start, int des, int &cnt)
    {
        if(start==des)
            cnt++;
        for(int neighbour: adj[start])
        {
            dfs(adj, n, neighbour, des, cnt);
        }
        return;
    }
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d)
	{
	    vector<int>adj[n];
	    for(auto e:edges)
	        adj[e[0]].push_back(e[1]);
	    
	    int cnt=0;
	    for(int i=0; i<n; i++)
	    {
	        if(i==s)
	            dfs(adj,n,i,d,cnt);
	    }
	    return cnt;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends