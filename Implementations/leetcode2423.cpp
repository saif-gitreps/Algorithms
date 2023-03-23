class Solution {
  // note : this solution was the closest i could get to solving my own. 
  // 45/49.
public:
    bool equalFrequency(string word) {
        set<char> s;
   int curr;
   for(int i=0;i<word.size();i++){
      curr = i;
      string temp = "";
      set<char> s;
      for(int j=0;j<word.size();j++){
         if(j!=curr) {
            s.insert(word[j]);
            temp += word[j];
         }
      }
      if(temp.size()%s.size()==0){
         return true;
      }
   }
   return false;
    }
};
