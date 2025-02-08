// had the same idea in mind, just something wrong with implementation
class Solution {
public:
    int tupleSameProduct(vector<int>& a) {
        unordered_map<int , int> mp;
        int ans = 0;

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                int pro = a[i] * a[j];
                ans += (mp[pro] * 8);
                mp[pro]++;
            }
        }

        return ans;
    }
};
