class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();int n=matrix[0].size();
            int i = 0, j = n- 1;
            int x=target;
            while (i < m && j >= 0) 
            {
                    if (matrix[i][j] == x) 
                        return true;
                    else if (matrix[i][j] > x)
                        j--;
                    else
                        i++;
            }   
            return false;
    }
};