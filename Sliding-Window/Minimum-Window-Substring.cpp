class Solution {
// THis almost worked.
public:
    string minWindow(string s, string t) {
        if(t == ""){
            return "";
        }
        if(s == t)
            return s;
        string ans = "";
        unordered_map<char,int> mp;
        int left = 0, count = 0, min_ln = s.size();
        for(auto c : t){
            mp[c]++;
        }
        for(int right = 0; right < s.size(); ++right){
            //to check if it is one of the char we need
            if(--mp[s[right]] >= 0){
                ++count;
            }
            // if we found all the chars in the curr window
            while(count == t.size()){
                if (min_ln > right - left + 1){
                    min_ln = right - left + 1;
                    ans = s.substr(left, min_ln);
                }
                if(++mp[s[left]] > 0){
                    -- count;
                }
                ++left;
            }
        }
        return ans;
    }
};
