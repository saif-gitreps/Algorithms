class Solution {
// YAYYYYYYYYY FIGURE IT OUT ON MY OWN
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mn = INT_MAX;
        long long sum = 0;
        int neg = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0) {
                    sum = sum + (-1 * matrix[i][j]);
                    neg++;
                }
                else {
                    sum += matrix[i][j];
                }
                mn = min(mn, matrix[i][j] < 0 ? -1 * matrix[i][j] : matrix[i][j]);   
            }
        }

        if (neg % 2 == 1) {
            return (sum - mn) + (mn * -1);
        } else {
            return sum;
        }
    }
};
