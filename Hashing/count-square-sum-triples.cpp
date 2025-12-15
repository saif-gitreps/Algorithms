class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        unordered_map<int, bool> mp;
        for (int i = 1; i <= n; i++) {
            mp[i*i] = true;
        }
        
        for (auto it: mp) {
            for (auto it2: mp) {
                if (mp.find(it.first + it2.first) != mp.end()){
                    count++;
                }
            }
        }

        return count;
    }
};
