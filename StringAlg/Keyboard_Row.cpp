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

class Solution {
  //attempt 2;
public:
    vector<string> findWords(vector<string>& words) {
        string u = "eiopqrtuwy";
        string m = "adfghjkls";
        string d = "bcmnvxz";
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            set<char> tem;
            for(auto x: temp){
                tem.insert(x);
            }
            int j =0;
            for(auto s: tem){
                if(s!=u[j]){
                    ++j;
                    break;
                }
            }
            if(j==tem.size()){
                ans.push_back(temp);
                continue;
            }
            j =0;
            for(auto s: tem){
                if(s!=m[j]){
                    ++j;
                    break;
                }
            }
            if(j==tem.size()){
                ans.push_back(temp);
                continue;
            }
            j =0;
            for(auto s: tem){
                if(s!=d[j]){
                    ++j;
                    break;
                }
            }
            if(j==tem.size()){
                ans.push_back(temp);
                continue;
            }
        }
        return ans;
    }
};
