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
