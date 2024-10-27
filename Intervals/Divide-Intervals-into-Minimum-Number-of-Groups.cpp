class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // solution is to find maximum overlap at any given time.
        // Alg 1: we find number of arrival and departure, mark arrival as +ve and departure as -ve, if we hit an arrival 
        // we count interval number by 1, and decrease interval if we hit a dep. 
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


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // solution is to find maximum overlap at any given time.
        // Alg 2: We will keep a diff array, ranging from 0 till max size of the problem, starting point will be marked 1 in the index  
        // and ending point will +1 , which will be marked as -1. goal is when we find a 1, we increase the count, and decrease when we find -1, ignore for 0.
        
        int count = 0;
        int mx = 1;
        vector<int> a(1e6 + 5, 0);

        for (auto i : intervals) {
            a[i[0]]++;
            a[i[1] + 1]--;
        }

        for (auto in : a) {
            count += in;
            mx = max(mx, count);
        }

        return mx;
    }
};
