class Solution {
// ran into a nasty edge case 93/185
public:
    int kev(int i,const vector<int> &a){
        if(i >= a.size()){
            return 0;
        }
        
        int sum = 0, ans = 0, n = a.size() - 1;
        
        for(int k = i; k < min(i + 3, n); k++){
            sum += a[k];
            ans = max(ans, sum + min({
                kev(i + k + 1, a),
                kev(i + k + 2, a),
                kev(i + k + 3, a)
            }));
        }

        return ans;
    }
    string stoneGameIII(vector<int>& stone) {
        int sum = 0; 
        for(auto s : stone) sum += s;
        int ans = kev(0, stone);
        
        if(ans > sum - ans){
            return "Alice";
        } 
        else if(ans == sum - ans){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};