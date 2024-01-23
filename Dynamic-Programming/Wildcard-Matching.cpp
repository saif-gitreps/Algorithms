class Solution {
// prolly the best recursive attempt i could come up with.
public:
    int kev(int i, int j,string s, string p, char wc){
        if(i == 0 && j == 0){
            if(s[i] == p[j] || p[j] == '?' || p[j] == '*'){
                return 1;
            }
            return 0;
        }
        if(i < 0){
            if(wc != '-1'){
                return 1;
            }
            return 0;
        }
        if(j < 0){
            if(i >= 0 && s[i] == wc){
                return kev(i - 1, j, s , p, wc);
            }
            else{
                wc = '-1';
                return 0;
            }
        }
        int ans = 0;
        if(s[i] == p[j]){
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        else if(p[j] == '?'){
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        else if(p[j] == '*'){
            wc = s[i];
            ans += kev(i - 1, j - 1, s, p, wc);
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        return kev(s.size()-1, p.size()-1, s, p, '-1');
    }   
};
