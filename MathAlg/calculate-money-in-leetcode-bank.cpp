class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int amount = 1;
        int week = 1;
        for (int i = 0; i < n; i++) {
            ans += amount;
            amount++;
            if (i % 7 == 0) {
                amount = week + 1;
                week++; 
            }
        }
        return ans;
    }
};

// some AP type shi

