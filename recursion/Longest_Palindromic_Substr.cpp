// first try , this only was built from left till s.size();
// incomplete.
class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> a;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            bool check = true;
            string word ="";
            int j;
            for(j=i;j<s.size();j++){
                if(s[j]!=s[n-j-1]){
                    check = false; break;
                }
            }
            if(check){
                a.push_back(s.substr(j,n-j));
            }
        }
    }
};
