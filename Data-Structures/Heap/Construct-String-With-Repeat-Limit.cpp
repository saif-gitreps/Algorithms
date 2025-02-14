class Solution {
// hey it worked, lets goooooo
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> q;
        int count = 1;

        unordered_map<char, int> freq;
    
        for (char c : s) {
            freq[c]++;
        }

        for (auto &[ch, count] : freq) {
            q.push({ch, count});  
        }

        string ans = "";

        while (q.empty() == false) {
            auto p = q.top();
            q.pop();
            int limit = repeatLimit;
            
            while (p.second && limit) {
                ans += p.first;
                p.second = p.second-1;
                --limit;
            }

            if (p.second > 0 && !q.empty()) {
                auto temp = q.top();
                q.pop();
                ans += temp.first;

                if (temp.second-1 >= 1) {
                    q.push({temp.first, temp.second-1});
                }
                
                q.push(p);
            }
        }
        return ans;
    } 
};

class Solution {
// better clever colution.
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);

        // Count character frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        int first = 25, second = 24;  // First is the largest available char, second is the next largest

        while (first >= 0) {
            if (freq[first] == 0) {
                --first;
                continue;
            }

            int use = min(freq[first], repeatLimit);  // Use at most `repeatLimit`
            freq[first] -= use;
            ans.append(use, 'a' + first);

            // If we still have more of `first` left, we must insert another character
            if (freq[first] > 0) {
                // Find the next largest available character
                while (second >= 0 && freq[second] == 0) {
                    --second;
                }

                if (second < 0) break;  // No more characters available, so we stop

                ans += ('a' + second);
                freq[second]--;
            }
        }

        return ans;
    }
};
