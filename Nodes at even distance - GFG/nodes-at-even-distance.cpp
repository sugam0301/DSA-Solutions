// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int countOfNodes(vector<int> adj[], int N)
    {
        int dist[N];
	for(int i = 1;i<=N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[1] = 0;
	q.push(1); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
        
        // Take 1 as source then find dist from it to every node.
        // Now find the nodes from dist[] where there is even distance and also odd dist
        // because odd + odd = even so find o for odd and e for even.
        // Now do oC2 and eC2 and add them
        
        int c1=0,c2=0;
        for(int i=1;i<=N;i++)
        {
           if(dist[i]%2==0)
               c1+=1;
           else
               c2+=1;
       }
       // oC2 and eC2
       return ((c1*(c1-1))/2)+((c2*(c2-1))/2);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends