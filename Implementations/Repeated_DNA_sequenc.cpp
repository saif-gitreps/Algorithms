class Solution {
  //naive solution , does beat TLE but worst performing solution.
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> a;
        for(int i=0;i+9<s.size();i++){
            m[s.substr(i,10)]++;
            //debug(s.substr(i,10));
        }
        for(int i=0;i+9<s.size();i++){
         string sub = s.substr(i,10); 
            if(m[sub]>1){
               a.push_back(sub);
               m[sub] = 0;
            }
        }
    return a;}
};
/*
although this is a java code , this beat 100%.
public List<String> findRepeatedDnaSequences(String s) {
    Set seen = new HashSet(), repeated = new HashSet();
    for (int i = 0; i + 9 < s.length(); i++) {
        String ten = s.substring(i, i + 10);
        if (!seen.add(ten))
            repeated.add(ten);
    }
    return new ArrayList(repeated);
}

*/

class Solution2 {
public:
  // my optimized solution , slightly better , like 6% better.
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> a;
        for(int i=0;i+9<s.size();i++){
            string sub = s.substr(i,10); 
            m[sub]++;
            if(m[sub]>1){
               a.push_back(sub);
               m[sub] = -1000000;
            }
        }
        return a;}
};
