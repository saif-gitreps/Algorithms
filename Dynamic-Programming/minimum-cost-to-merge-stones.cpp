class Solution {
// tis recursion worked, the -1 case could be solved with a check.
public:
    int kev(int i, vector<int> a, int k){
        if(a.size() < k){
            return -1;
        }
        if(a.size() == k){
            int sum = 0;
            for(auto nums : a){
                sum += nums;
            }
            return sum;
        }
        int pick = INT_MAX;
        int not_pick = INT_MAX;
        int sum = 0;
        vector<int> temp;
        int flag = true;
        for(int ind = 0; ind < a.size(); ind ++){
            if(ind == i){
                if(k > a.size()){
                    flag = false;
                    break;
                }
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
        if(flag){
            pick = sum + kev(0, temp, k);
        }
        if(i + k < a.size()){
            not_pick = kev(i + 1, a, k);
        }
        return min(pick, not_pick);
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) 
            return -1;
        if(stones.size() == 1){
            return 0;
        }
        return kev(0, stones, k);
    }
};
