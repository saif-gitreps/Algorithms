// bool comparator(vector<int> &a, vector<int> &b) {
//     return a[0] < b[0];
// }

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int, int> mp;

        for (int i = 0; i < items.size(); i++) {
            if (mp.find(items[i][0]) == mp.end()) {
                mp[items[i][0]] = items[i][1];
            } else {
                mp[items[i][0]] = max(mp[items[i][0]], items[i][1]); 
            }
        }
        
        int maxBeauty = 0;
        for (auto& [price, beauty] : mp) {
            maxBeauty = max(maxBeauty, beauty);
            mp[price] = maxBeauty;
        }

        vector<int> result(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            auto it = mp.upper_bound(q);

            if (it == mp.begin()) {
                result[i] = 0;
            } else {
                --it;
                result[i] = it->second;
            }
        }

        return result;
    }
};
