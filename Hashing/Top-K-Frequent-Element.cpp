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

class Solution {
// i kind of cant find better solution than mine, but here is a code that appararently heapifies.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x] += 1;

        vector<pair<int, int>> maxHeap;
        for (auto [num, freq] : cnt) maxHeap.emplace_back(freq, num);
        make_heap(maxHeap.begin(), maxHeap.end()); // default is maxHeap

        vector<int> ans;
        while (k-- > 0) {
            auto [_, num] = maxHeap[0];
            pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back(); // delete the unused last element

            ans.push_back(num);
        }
        return ans;
    }
};


class Solution {
// This is neet's bucket sort algorithm , it apparently and theoretically works O(n) times. space O(n) at most.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<vector<int>> hash(nums.size()+1);
        for(auto n : nums){
            mp[n]++;
        }
        for(auto m: mp){
            hash[m.second].push_back(m.first);
        }
        for(int i = hash.size()-1; i >= 0; i--){
            for(auto n : hash[i]){
                ans.push_back(n);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;   
    }
};
