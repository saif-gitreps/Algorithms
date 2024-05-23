class Solution {
// Its not that the solution is wrong, its the flaw of DFS alg coming to light.
// TLE at 115 / 145 cases. Need to implement one with BFS.
public:
    bool kev(int j, int minj, int maxj, string &a){
        if(j == a.size() - 1 && a[j] == '0'){
            return true;
        }
        if(j >= a.size()){
            return false;
        }

        int n = a.size();

        for(int k = j + minj; k <= min(j + maxj, n - 1); k++){
            if(a[k] == '0' && kev(k, minj, maxj, a)){
                return true;
            }
        }
        return false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        return kev(0, minJump, maxJump, s);
    }
};
