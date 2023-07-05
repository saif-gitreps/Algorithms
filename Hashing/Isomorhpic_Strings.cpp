class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapper;
        unordered_map<char,bool> taken;
        for(int i=0;i<s.size();i++){
            if(!mapper.count(s[i]) && taken[t[i]]==false){
               mapper[s[i]] = t[i];
               taken[t[i]] = true;
            }
            else if(!mapper.count(s[i]) && taken[t[i]]==true){
               return false;
            }
            if(mapper.count(s[i])){
               if(t[i]!=mapper[s[i]]){
                  return false;
               }
            }
        }
        return true;
    }
};
