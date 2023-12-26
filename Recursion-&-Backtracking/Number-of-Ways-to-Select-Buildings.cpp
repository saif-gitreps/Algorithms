class Solution {
//bruteforce approach , shows tle
public:
    void rev(int i,string s,string &ds,long long &count){
   if(ds.size()==3){
      count++;
      return;
   }
   if(i>=s.size()){
      return;
   }
   for(int j=i;j<s.size();j++){
      if(ds.back()==s[j]){
         continue;
      }
      else{
         ds.push_back(s[j]);
         rev(j+1,s,ds,count);
         ds.pop_back();
      }
   }
}

long long numberOfWays(string s) {
      long long count = 0;
      string ds;
      rev(0,s,ds,count);
      return count;
}

};

class Solution {
// naive bruteforce , show tle.
public:
    long long numberOfWays(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                for(int k = j + 1; k < s.size(); k++){
                    if(s[i] != s[j] && s[j] != s[k]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

