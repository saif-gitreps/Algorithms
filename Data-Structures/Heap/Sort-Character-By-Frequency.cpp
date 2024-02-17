class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> q;

        for(int i = 0 ; i < s.size(); i++){
            mp[s[i]] ++;
        }

        for(auto c : mp){
            q.push({c.second, c.first});
        }
        s = "";
        while(q.empty() == false){
            int size = q.top().first;
            while(size--){
                s += q.top().second;
            }
            q.pop();
        }
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch: s)
            ++counts[ch];
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};

//So the trade-off is, u either use extra O(n) space to get TC O(n) or use TC O (nlogn) but reduce SC O(n).
