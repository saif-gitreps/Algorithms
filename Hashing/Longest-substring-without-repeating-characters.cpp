class Solution {
//attempt 1 worked till 407/900 test cases.
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = -1;
        int prev_len = 0;
        set<char> mySet;
        for(int i = 0 ; i<s.size(); i++){
            mySet.insert(s[i]);
            if(mySet.size()>prev_len){
                prev_len = mySet.size();
                max_len = max(max_len,prev_len);
            }
            else{
                prev_len = 1;
                set<char> newSet;
                newSet.insert(s[i]);
                mySet = newSet;
            }
        }
        return max_len==-1?0:max_len;
    }
};
