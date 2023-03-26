class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i+needle.size()-1<haystack.size();i++){
            if(haystack.substr(i,needle.size())==needle){
                return i;
            }
        }
        return -1;
    }
};
class Solution2 {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length();
        int h=haystack.length();
        if(h>=n){
            return haystack.find(needle);
        }
        return -1;
    }
};
