//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    private:
    bool isvalid(int nx,int ny, int M, int N)
    {
        if(nx>=0 && ny>=0 && nx<M && ny<N)
            return 1;
        return 0;
    }
    
    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<bool>>vis(M,vector<bool>(N,false));
        vector<vector<int>>res(M,vector<int>(N,-1));
        queue<pair<int,int>>q;
        
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(matrix[i][j]=='B')
                {
                    q.push({i,j});
                    vis[i][j] = true;
                    res[i][j] = 0;
                }
                else if(matrix[i][j]=='W')
                {
                    res[i][j] = -1;
                }
            }
        }
        
        int level = 0;
        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};
        
        
        while(q.size())
        {
            int cnt = q.size();
            level++;
            for(int ind =0; ind<cnt;ind++)
            {
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                for(int i=0;i<4;i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(isvalid(nx,ny,M,N))
                    {
                        if(!vis[nx][ny] && matrix[nx][ny] == 'O')
                        {
                            res[nx][ny] = level; 
                            vis[nx][ny] = true;
                            q.push({nx,ny});
                        }   
                    }
                }
            }
                
        }        
            return res;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends