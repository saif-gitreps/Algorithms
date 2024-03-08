class Solution {
// i was 90% right, the only confusion i had was , how do we calculate the ratio after hashing.
// the other way would be to use an unordered map and use double, divide the ratio and hash the decimal.

public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int> , long long> mp; 
        long long ans = 0;

        for(int i = 0; i < rectangles.size(); i++){
            int gcd = __gcd(rectangles[i][0], rectangles[i][1]);

            pair<int, int> ratio = {
                rectangles[i][0]/gcd,
                rectangles[i][1]/gcd
            };

            if(mp.count(ratio)){
                ans += mp[ratio];
            }

            mp[ratio]++;

        }

        return ans;
    }
};
