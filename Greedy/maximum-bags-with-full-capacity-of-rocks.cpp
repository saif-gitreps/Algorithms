class Solution {
// SUIII , worked.
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int ar) {
        multiset<long long> st;

        for(int i = 0; i < cap.size(); i++){
            long long diff = cap[i] - rocks[i];
            st.insert(diff);
        }

        int ans = 0;
        for(auto diff: st){
            if(ar < 0){
                break;
            }
            if(diff == 0){
                ans ++;
            }
            else{
                ar -= diff;
                if(ar >= 0){
                    ans ++;
                }
            }
        }
        return ans;
        
    }
};
