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

class Solution {
    // brute force approach , works till 40 cases, then shows SLE (space limit exceeding).
public:
    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_length = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)==true){
                    if(j-i+1>max_length){
                        max_length = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index,max_length);
    }
};
