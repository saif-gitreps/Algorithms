class Solution {
// the recursions works, i need to find a way to do the dp.
public:
    int kev(int n, string str, string s, string t, vector<int> &dp){
        if(n == s.size() - 1){
            if(str == t){
                return 1;
            }
            str += s[n];
            if(str == t){
                return 1;
            }
            else{
                return 0;
            }   
        }
        if(str == t){
            return 1;
        }
        int pick = 0;
        int not_pick = 0;
        str += s[n];
        pick = kev(n + 1, str, s, t, dp);
        str.pop_back();

        not_pick = kev(n + 1, str, s, t, dp);
        return  pick + not_pick;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return kev(0 ,"", s, t, dp);
    }

};
