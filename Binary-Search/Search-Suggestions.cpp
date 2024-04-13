class Solution {
// solution was what I anticipated and intuited.
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        sort(p.begin(), p.end());
        string str = "";
        vector<vector<string>> ans;
        for (auto c : s){
            
            str += c;
            
            vector<string> w;
                

            auto it = lower_bound(p.begin(), p.end(), str);
            
            for (int i = 0; i < 3 and it + i != p.end(); i++){
                string& temp = *(it + i);
 //If temp doesn't start with str, then break               
if (temp.find(str)) 
                    break;
                w.push_back(temp);
                }
            ans.push_back(w);
            
        }
        return ans;
        
    }
};