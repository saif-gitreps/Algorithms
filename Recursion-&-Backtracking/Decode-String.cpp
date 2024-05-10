class Solution {
// Had damn similar idea and intuition but failed to implement the code.
public:
    string kev(int& i, string s){
        string ans = "";
        while(i < s.size() && s[i] != ']'){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
                i++;
            }
            else{
                int num = 0;
                while(i < s.size() && (s[i] >= '0' && s[i] <= '9')){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string res = kev(i, s);
                i++;
                for (int j = 1; j <= num; j++){
                    ans += res;
                }
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i =0;
        string ans = kev(i, s);
        
        return ans;
    }
};

class Solution {
// tHis solution is more close to the one i tried.
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    // Normal characters
                word += cur;
            }
        }
        return word;
    }
};
