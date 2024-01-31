class Solution {
// idea is that we find the minimum on the left and max on the right,
// such that the index of the min is always on the left of the rightMax.
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mx = 0;

        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - mn;
            mx = max(mx, cost);
            mn = min(mn, prices[i]);
        }

        return mx;
    }
};
