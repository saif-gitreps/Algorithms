class Solution {
// naive algorithm but works.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto n : nums){
            mp[n]++;
        }
        for(auto m: mp){
            pq.push({m.second, m.first});
        }
        while(k >= 1){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;    
    }
};
