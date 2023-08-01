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
class Solution {
//attempt 2: cant figure out the damn thing 
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = -1;
        int seq = 0;
        unordered_map<char,int> mp;
        for(int i = 0 ; i<s.size(); i++){
            if(mp.count(s[i])==false){
                mp[s[i]] = i;
                seq++;
                max_len = max(max_len,seq);
            }
            else{
                seq = abs((mp[s[i]]+1)-(i+1));
                mp[s[i]] = i;
                 max_len = max(max_len,seq);
            }
        }
        return max_len==-1?0:max_len;
    }
};
