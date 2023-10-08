class Solution {
// tried somethig , sorta works.
public:
    string replaceWords(vector<string>& d, string s) {
        string ans = "";
        string word = "";
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                bool found = false;
                for(int j = 0; j < d.size(); j++){
                    if(d[j][0] == word[0]){
                        found = true;
                        int k = 0;
                        while(k < d[j].size() || d[j][k] == word[k]){
                            ans += d[j][k];
                            k++;
                        }
                        ans += " ";
                        break;
                    }
                }
                if(!found){
                    ans += word;
                    ans += " ";
                }
                word = "";
            }
        }
        return ans;
    }
};
