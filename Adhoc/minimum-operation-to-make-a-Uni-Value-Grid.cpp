class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int tn = m * n, tc = 0;
        int a[tn];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i * n + j] = grid[i][j];
        sort(a, a + tn);
        int mid = tn / 2;
        for (int i = 0; i < tn; i++) {
            if ((abs(a[i] - a[mid])) % x != 0)
                return -1;
            tc += abs(a[i] - a[mid]) / x;
        }
        return tc;
    }
};
       


#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> all;
        
        for (auto& row : grid) {
            for (int num : row) {
                all.push_back(num);
            }
        }

        int mod = all[0] % x;
        for (int num : all) {
            if (num % x != mod) return -1;
        }

        sort(all.begin(), all.end());
        int median = all[all.size() / 2];
        int operations = 0;

        for (int num : all) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
}; 