class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        float mx_diag;
        int mx_area;
        for (auto d: dimensions) {
            float c = sqrt(d[0] * d[0] + d[1] * d[1]);
            if (c > mx_diag) {
                mx_area = d[0] * d[1];
                mx_diag = c;
            } else if (c == mx_diag && d[0] * d[1] > mx_area) {
                mx_area = d[0] * d[1];
                mx_diag = c;
            }
        }

        return mx_area;
    }
};
