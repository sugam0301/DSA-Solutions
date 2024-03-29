/* This problem requires us to implement a multiset (as elements can repeat). To acheive this using the PBDS, we can use a pair<int,int> as the key where the second element in the pair is a unique timestamp (corresponding to each entry in the set). This allows us to insert multiple entries for a given number.  */


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> set_t;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        set_t s;    //GNU PBDS - ordered set
        int time = 0;
        s.insert({nums.back(), time++});
        for(int i = n - 2; i >= 0; i--)
        {
            ans[i] = s.order_of_key({nums[i], 0});
            s.insert({nums[i], time++});
        }
        return ans;
    }
};