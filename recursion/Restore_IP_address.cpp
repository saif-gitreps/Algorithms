class Solution {
  // need to study this solution .
public:
void helper(string& s,int i,int par,string ans,vector<string>& res){
   if(i==s.size() || par==4){
      if(s.size()==i && par==4){
         // this is for the last .
         res.push_back(ans.substr(0,ans.size()-1));
      }
      return;
   }
   helper(s,i+1,par+1,ans+s[i]+".",res);
   
   if(i+2<=s.size() && isvalid(s.substr(i,2))){
      helper(s,i+2,par+1,ans+s.substr(i,2)+".",res);
   }
   if(i+3<=s.size() && isvalid(s.substr(i,3))){
      helper(s,i+3,par+1,ans+s.substr(i,3)+".",res);
   }
}

bool isvalid(string str){
   if(str[0]=='0'){
      return false;
   }
   return stoi(str)<=255;
}
   vector<string> restoreIpAddresses(string s) {
      vector<string> ans;
      helper(s,0,0,"",ans);
      return ans;
    }
};
