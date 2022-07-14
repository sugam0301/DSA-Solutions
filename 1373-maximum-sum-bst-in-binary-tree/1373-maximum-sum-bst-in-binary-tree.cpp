// int ans;
// class Nodevalue{
//   public:
//     int maxNode, minNode, size, sum;
    
//     Nodevalue(int minNode, int maxNode, int size, int sum) {
//         this->minNode = minNode;
//         this->maxNode = maxNode;
//         this->size = size;
//         this->sum = sum;
//     }
// };

// class Solution {
// public:
//     Nodevalue util(TreeNode* root) 
//     {
//         if (!root) 
//             return Nodevalue(INT_MAX, INT_MIN, 0,0);
        
//         auto left = util(root->left);
//         auto right = util(root->right);
        
//         if (left.maxNode < root->val && root->val < right.minNode) 
//         {
//             ans = max(ans, left.sum + right.sum + root->val);
//             // It is a BST.
//             return Nodevalue(min(root->val, left.minNode), max(root->val, right.maxNode), left.size + right.size + 1, left.sum + right.sum + root->val );
//         }
        
//         // Otherwise, return [-inf, inf] so that parent can't be valid BST
//         return Nodevalue(INT_MIN, INT_MAX, max(left.size, right.size), max(left.sum,right.sum));
//     }
    
    
//     int maxSumBST(TreeNode* root) 
//     {
//         ans =  util(root).sum;   
//         return ans>0?ans:0;
//     }
// };


int ans;
class nodevalue{
    public:
    int minvalue,maxvalue, mxsum;
    nodevalue(int minvalue,int maxvalue,int mxsum){
        this->minvalue=minvalue;
        this->maxvalue=maxvalue;
        this->mxsum=mxsum;
    }
};
class Solution {
    nodevalue maxSumBSThelper(TreeNode* root){
        if(root==NULL)
            return nodevalue(INT_MAX,INT_MIN,0);
        auto left=maxSumBSThelper(root->left);
        auto right=maxSumBSThelper(root->right);
        if(root->val>left.maxvalue && root->val<right.minvalue){
            ans = max(ans, left.mxsum + right.mxsum + root->val);
            return nodevalue(min(root->val,left.minvalue),max(root->val,right.maxvalue),left.mxsum + right.mxsum + root->val);
        }
        return nodevalue(INT_MIN,INT_MAX,max(left.mxsum,right.mxsum));
    }
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        maxSumBSThelper(root);
        return ans >0 ? ans : 0;
    }
};
