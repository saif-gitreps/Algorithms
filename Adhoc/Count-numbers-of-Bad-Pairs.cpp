class Solution {
// similar idea , to take max pair in account and then calucalte the valid.
// sub max pair and valid pair, had confusion in calculating valid pair.
// here we take a sum of : lets say 1 2 3 4 
// 0 - 1 = -1 , with 1 , we have 0 pair.
// 1 - 2 = -1 , with 2 , we have 1 pair. and so on.
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total_pairs = ((long long)n * (n-1)) / 2;
        unordered_map<long long ,long long> mp;

        long long mx = 0;
        for(int i = 0; i < n; i++){
            mp[i - mp[i]] ++;
        }
        for(auto s : mp){
            mx = max(s.second, mx);
        }
        return abs(total_pairs - mx;
    }
};
