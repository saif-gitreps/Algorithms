class Solution {
// my solution , works.
// TC -> O(n^2) .
// space -> O(n^2).
public:
    int to_number(string s){
        int num = 0;
        for(int i = 0; i < s.size();i++){
            num = num*10 + (s[i] - '0');
        }
        return num;
    }
    int maximumSwap(int num) {
        if(num >= 1 && num <=9){
            return num;
        }
        string s = to_string(num);
        int mx = num;
        for(int i = 0 ; i < s.size() ;i ++){
            string temp = s;
            for(int j = i; j < s.size(); j++){
                temp = s;
                swap(temp[i],temp[j]);
                if(temp[0] == '0'){
                    continue;
                }
                mx = max(mx,to_number(temp));     
            }
        }
        return mx;
    }
};
