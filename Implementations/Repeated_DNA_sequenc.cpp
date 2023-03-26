class Solution {
  //naive solution , does beat TLE but worst performing solution.
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> a;
        for(int i=0;i<s.size();i++){
            m[s.substr(i,10)]++;
            //debug(s.substr(i,10));
        }
        for(int i=0;i<s.size();i++){
         string sub = s.substr(i,10); 
            if(m[sub]>1){
               a.push_back(sub);
               m[sub] = 0;
            }
        }
    return a;}
};
