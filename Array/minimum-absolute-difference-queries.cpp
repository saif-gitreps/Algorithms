class Solution {
// Well this was my concept, but i was well off ,it was mostly prefix sum and BS type of problem.
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        map<pair<int,int>,int> mp;
        vector<int> ans;
        for(int i = 0; i < q.size(); i++){
            int mn = INT_MAX;
            for(auto s : mp){
                if(s.first.first >= q[i][0] && s.first.second <= q[i][1]){
                    if(s.second == -1){
                        continue;
                    } 
                    mn = min(mn, s.second);
                }
            }
            if(mn == INT_MAX){
                for(int j = q[i][0]; j+1 <= q[i][1]; j++){
                    int diff = abs(nums[j]-nums[j+1]);
                    // this part of code is incomplete.
                }
            }
            ans.push_back(mn);
        }
    return ans;
    }
};
