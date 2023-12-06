class Solution {
//Lets fucking go boys, first attempt, no failure, PASS SUIIII.
public:
    vector<vector<string>> ans;
    bool check(string s){
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] != s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    void kev(int i, vector<string> &ds, string s){
        if(i == s.size()){
            for(auto item: ds){
                if(check(item) == false){
                    return;
                }
            }
            ans.push_back(ds);
            return;
        }
        string str = "";
        for(int j = i; j < s.size(); j++){
            str += s[j];
            ds.push_back(str);
            kev(j + 1, ds, s);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        kev(0, ds, s);
        return ans;
    }
};
