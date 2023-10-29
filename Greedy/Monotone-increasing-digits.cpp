class Solution {
public:
    bool check_mono(int n){
        string s = to_string(n);
        for(int i = 1 ; i < s.size(); i++){
            if(s[i-1]-'0' > s[i]-'0'){
                return false;
            }
        }
        return true;
    }
    int monotoneIncreasingDigits(int n) {
        // Bruteforce approach.
        if(check_mono(n)){
            return n;
        }
        while(check_mono(n) == false){
            n--;
        }
        return n;
    }
};
