class Solution {
// first attempt , idk what i am trying.
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = -1;
        for(int i = 0 ; i < piles.size(); i++){
            mx = max(piles[i],mx);
        }
        int mid ,left = 1, right = mx;
        while(left<=right){
            mid = left + (right - left)/2;
            if((mx/mid)*piles.size()>h){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};

    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2, total = 0;
            for (int p : piles)
                total += (p + m - 1) / m;
            if (total > H)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
