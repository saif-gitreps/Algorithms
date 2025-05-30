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

class Solution {
// naive approach.
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for (const auto &it: mp) {
            pq.push({
                it.second,
                it.first
            });
        }
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        // we know that the max frequency of any number is size of nums.
        // we also that every frequency is unique;
        // we will index the frequency with an array, although all the frequencies are unique, we still need to account for the case where a single frequency has multiple element of nums.

        vector<vector<int>> freq(nums.size()+1);
        vector<int> ans;
        for (const auto &it: mp) {
            freq[it.second].push_back(it.first);
        }

        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            if (freq[i].size() > 0) {
                // now you might be thinking, wait if are starting a loop, then wont all the number belonging to a same frequency get pushed? Nah that won't happen because other than 1, evry other frequencies are unique, besides this loop exists for the test case where all the frequencies are 1.
                for (auto num : freq[i]) {
                    ans.push_back(num);
                    if (ans.size() == k) {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
