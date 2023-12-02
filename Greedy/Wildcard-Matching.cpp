class Solution {
//Tried something greedily, i think i didnt understand the problem properly but this worked for 1300/1800.
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        while(i < s.size() && j < p.size()){
            if(p[j] == '*'){
                return true;
            }
            if(s[i] != p[j]){
                if(p[i] == '?'){
                    ++i;
                    ++j;
                    continue;
                }
                else{
                    break;
                }
            }
            ++i;
            ++j;
        }
        if(i < s.size() || j < p.size()){
            return false;
        }
        return true;
    }
};
