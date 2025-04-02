class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mx = max(mx, grid[i][j]);
            }
        }
        vector<int> mp(mx + 1, 0);
        
        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        
        for (int i = 1; i <= mx; i++) {
            if (mp[i] > 1) {
                ans[0] = i;
            }
            if (mp[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mp(n * n + 1, 0);

        for(int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]]++;
            }
        }
        vector<int> ans(2);
        
        for (int i = 1; i <= n * n; i++) {
            if (mp[i] > 1) {
                ans[0] = i;
            }
            if (mp[i] == 0) {
                ans[1] = i;
            }
        }

        return ans;
    }
};
