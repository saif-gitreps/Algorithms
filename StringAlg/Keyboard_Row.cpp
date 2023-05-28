class Solution {
  //attempt one.
public:
    vector<string> findWords(vector<string>& words) {
        string u = "qwertyuiop";
        string m = "asdfghjkl";
        string d = "zxcvbnm";
        set<char> up;
        set<char> middle;
        set<char> down;
        for(auto s: u){
            up.insert(s);
        }
        for(auto s: m){
            middle.insert(s);
        }
        for(auto s: d){
            down.insert(s);
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            set<char> tem;
            for(auto x: temp){
                tem.insert(x);
            }
            if()
        }

    }
};
