class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<pair<int, int>> s;  
        vector<int> ans(t.size(), 0);
        for (int i = 0; i < t.size(); i++) {
            if(s.size() == 0 || s.back().first >= t[i]) {
                s.push_back({t[i], i});
            } else {
                if (s.back().first < t[i]) {
                    while (s.size() >= 1 && s.back().first < t[i]) {
                        ans[s.back().second] = i - s.back().second;
                        s.pop_back();
                    }
                    s.push_back({t[i], i});
                }
            }
        }

        return ans;
    }
};
