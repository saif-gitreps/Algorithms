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



class Solution {
// most of the people have this type of solution.
  public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> path;
      partitionHelper(0, s, path, res);
      return res;
    }

  void partitionHelper(int index, string s, vector<string> & path,
    vector<vector<string>> & res) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        partitionHelper(i + 1, s, path, res);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
};
