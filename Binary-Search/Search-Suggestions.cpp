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
 /* If temp doesn't start with str, then break, So understood this ,
Basically find will return the index of the occurense of substring in A.find(B), 
if B is a substr found at index 0 or starting then we know we can take it. 
If the find returns any value from 1 till end that means the found product does not have a prefix with the search word */            
if (temp.find(str)) 
                    break;
                w.push_back(temp);
                }
            ans.push_back(w);
            
        }
        return ans;
        
    }
};