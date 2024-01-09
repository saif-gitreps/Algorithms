class Solution {
// getting on the right track here, have to figure out -1 cases.
public:
    int kev(int i, vector<int> a, int k){
        if(a.size() == k){
            int sum = 0;
            for(auto nums : a){
                sum += nums;
            }
            return sum;
        }
        if(a.size() < k){
            return -1;
        }
        int pick = INT_MAX;
        int not_pick = INT_MAX;
        int sum = 0;
        vector<int> temp;
        for(int ind = 0; ind < a.size(); ind ++){
            if(ind == i){
                for(int p = k;ind  < a.size() && p >= 1; p-- ){
                    sum += a[ind++];
                }
                temp.push_back(sum);
                ind--;    
            }
            else{
                temp.push_back(a[ind]);
            }
        }
        pick = sum + kev(0, temp, k);
        if(i + k < a.size()){
            not_pick = kev(i + 1, a, k);
        }
        return min(pick, not_pick);
    }
    int mergeStones(vector<int>& stones, int k) {
        return kev(0, stones, k);
    }
};
