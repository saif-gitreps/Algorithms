class Solution {
// So i had similar Idea in mind, of using knapsack method.
// the problem with my implementation : I needed a copy of original needs array for not_pick, i didnt know how
// to do it other than creating a temp which itself was mess, but the solution was easy, just call not_pick before.

// the other idea was i mean i am looping through all the sp 2D array , why not just use i instead of a inner 
// recursive for loop.
public:
    int kev(int i,const vector<vector<int>> sp,const vector<int> pr, vector<int> n){
        if(i == sp.size()){
            int res = 0;
            for(int k = 0; k < n.size(); k++){
                res += (n[k] * pr[k]);
            }
            return res;
        }
        
        int pick = INT_MAX, not_pick = INT_MAX;
        not_pick =  kev(i + 1, sp, pr, n);
        
        for(int k = 0; k < n.size(); k++){
            n[k] -= sp[i][k];
            if(n[k] < 0){
                return not_pick;
            }
        }
        pick =  sp[i][n.size()] + kev(i, sp, pr, n);
    
        return min(pick, not_pick);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return kev(0, special, price, needs);
    }
};
