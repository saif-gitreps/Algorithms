class Solution {
public:
// passed like 80/180 cases.
    bool equationsPossible(vector<string>& equations) {
        unordered_map<string, int> mp;
        for(int i = 0; i < equations.size(); i++){
            string str = ""; 
            str += equations[i][1];
            str += equations[i][2];
            mp[str]++;
        }

        if(mp["=="] == equations.size() || mp["!="] == equations.size()){
            return true;
        } else{
            return false;
        }
    }
};
