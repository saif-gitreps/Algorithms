class Solution {
// idk the bruteforce worked. Not the best but atleast it worked.
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        vector<int> ans;
        
        for(auto interval : a){
            int mn = INT_MAX, mn_index = -1;
            for (int i = 0; i < a.size(); i++) {
                if (a[i][0] >= interval[1]) {
                    if (a[i][0] < mn) {
                        mn = a[i][0];
                        mn_index = i; 
                    }
                }
            }

            ans.push_back(mn_index);
        }

        return ans;
    }
};
