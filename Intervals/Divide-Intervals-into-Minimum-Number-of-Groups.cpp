class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // solution is to find maximum overlap at any given time.
        // Alg 1: we find number of arrival and departure, mark arrival as +ve and departure as -ve, if we hit an arrival we count interval number by 1, and decrease interval if we hit a dep. 
        int count = 0;
        int mx = 1;
        vector<pair<int,int>> a;

        for (auto i : intervals) {
            a.push_back({i[0], 1});
            a.push_back({i[1] + 1, -1});
        }

        sort(a.begin(), a.end());

        for (auto in : a) {
            if (in.second == 1) 
                ++count;
            else if (in.second == -1)
                --count;

            mx = max(mx, count);
        }

        return mx;
    }
};
