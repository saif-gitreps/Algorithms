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


class Solution {
// i am so stupid, i could have just utilized one of array and stored the diff, sorted it. similar sol to mine
// but with space(1), whereareas my space is O(n).
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int ar) {
        for(int i = 0; i < cap.size(); i++){
            rocks[i] = cap[i] - rocks[i];
        }
        sort(rocks.begin(), rocks.end());
        int ans = 0;
        for(auto diff: rocks){
            if(ar < 0){
                break;
            }
            ar -= diff;
            if(ar >= 0){
                ans ++;
            }
        }
        return ans;
        
    }
};
