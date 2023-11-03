class Solution {
// Bruteforce works, time to memoize.
public:
    int kev(int n, int s1, int s2, vector<int> a){
        if(n == 0){
            if(s1 + a[n] == s2 || s2 + a[n] == s1){
                return 1;
            }
            return 0;
        }
        int s1_pick = 0;
        int s2_pick = 0;
        s1_pick = kev(n-1, s1+a[n], s2, a);
        s2_pick = kev(n-1, s1, s2+a[n], a);
        return s1_pick || s2_pick;
    }
    bool canPartition(vector<int>& nums) {
        return kev(nums.size()-1, 0, 0, nums);
    }
};
