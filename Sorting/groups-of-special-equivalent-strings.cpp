class Solution {
https://leetcode.com/problems/groups-of-special-equivalent-strings/solutions/163412/c-simple-solution/
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> s;

        for(auto w : words){
            
            vector<string> temp(2, "");

            for(int i = 0; i < w.size(); i++){
                
                if(i % 2 != 0){
                    
                    temp[0] += w[i];
                }
                else{
                    
                    temp[1] += w[i];
                }

            }
                sort(temp[0].begin() ,temp[0].end());
                sort(temp[1].begin(), temp[1].end());

                s.insert(temp[0] + temp[1]);
        }
        
        return s.size();
    }
};
