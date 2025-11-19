class Solution {
// isnt working
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int left = 0;
        int right = a.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (left == right) {
                int L = 0;
                int R = a[left].size()-1;
                while (L <= R) {
                    int m = L + (R - L) / 2;
                    if (a[left][m] == target) {
                        return true;
                    } else if (a[left][m] < target) {
                        L = m + 1;
                    } else {
                        R = m - 1;
                    }
                }
            }

            if (a[mid][0] < target) {
                left = mid + 1;
            } else if (a[mid][0] > target){
                right = mid - 1;
            }
        }

        return false;
    }
};
