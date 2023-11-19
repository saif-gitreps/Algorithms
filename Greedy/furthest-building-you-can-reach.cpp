class Solution {
// first attempt 60/78 cases passed.
public:
    int furthestBuilding(vector<int>& h, int b, int lad) {
        int ans = 0;
        for(int i = 1 ; i < h.size(); i++){
            if(b <= 0 && lad <= 0){
                if(h[i-1] > h[i]){
                    ans++;
                    continue;
                }
                else{
                    break;
                }                
            }
            if(h[i-1] > h[i]){
                ans++;
            }
            else{
                if(b >= abs(h[i-1]-h[i])){
                    b -= abs(h[i-1]-h[i]);
                    ans++;
                }
                else if(lad >= 1){
                    lad--;
                    ans++;
                }
            }
        }
        return ans;
    }
};
