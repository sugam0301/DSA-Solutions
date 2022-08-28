class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size(), col = mat[0].size();
        
        for(int k = 0; k + 1 < row; k++)
        {
             for(int i = 0; i + 1 < row; i++)
             {
                for(int j = 0; j + 1 < col; j++)
                {
                    
                    if(mat[i][j] > mat[i + 1][j + 1])
                    {
                        swap(mat[i][j], mat[i + 1][j + 1]);   
                    }
                    
                }
             }
        }
        
        return mat;
    }
};