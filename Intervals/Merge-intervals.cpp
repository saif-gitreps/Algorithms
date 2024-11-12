class Solution {
// sort
// Take the first interval and push it array is empty
// if there is an interval that meets the condition of {1, 2} , {2, 4}, where first one is in the ans arr.
// We will merge it by taking the max of int1 ending and int2 ending.
// for the edge case where {1. 4} , {2,3} , where int1 ending is greater than both points, we continue.
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // bruteforce
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.size()) {
              if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
              } else if (ans.back()[1] >= intervals[i][1]){
                continue;
              } else {
                ans.push_back(intervals[i]);
              }
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
