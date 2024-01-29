class Solution {
// we really didint need any dp or monotonic stack, i think sometimes thinking of the the simplistic 
// 
public:
    int minNumberOperations(vector<int>& target) {
        int mn = target[0];

        for(int i = 1 ; i < target.size(); i++){
            if(target[i - 1] < target[i]){
                mn += (target[i] - target[i - 1]);
            }
        }

        return mn;
    }
};
