class Solution {

public:
    int findRotateSteps(string ring, string key) {
        unordered_map<string, int> memo;
        return dfs(ring, key, 0, memo);
    }

private:
    int dfs(const string& ring, const string& key, int index, unordered_map<string, int>& memo) {
        if (index == key.size()) {
            return 0;
        }

        char c = key[index];
        string hashKey = ring + to_string(index);
        if (memo.find(hashKey) != memo.end()) {
            return memo[hashKey];
        }

        int minSteps = INT_MAX;
        for (int i = 0; i < ring.size(); ++i) {
            if (ring[i] == c) {
                string s = ring.substr(i) + ring.substr(0, i);
                int steps = 1 + min(i, static_cast<int>(ring.size()) - i);
                steps += dfs(s, key, index + 1, memo);
                minSteps = min(minSteps, steps);
            }
        }

        memo[hashKey] = minSteps;
        return minSteps;
    }
};
