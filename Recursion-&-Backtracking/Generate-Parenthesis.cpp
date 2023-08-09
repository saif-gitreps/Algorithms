class Solution {
// all the parenthesis looks good to me , i dont know why its still wrong answer.
public:
    bool valid(string a){
   stack<char> s;
   for(int i=0;i<a.size();i++){
      if(a[i]=='('){
         s.push(a[i]);
      }
      else if(!s.empty() && a[i]==')' && s.top()=='('){
         s.pop();
      }
      else {
         return false;
      }
   }
   return true;
}

void kev(int i,string &a,set<string> &ans){
        if(i>=a.size()){
//           if(valid(a))
               ans.insert(a);

            return;
        }
        for(int j=i;j<a.size();j++){
           swap(a[i],a[j]);
           kev(j+1,a,ans);
           swap(a[i],a[j]);
        }
    }
    string gen(int n){
        string s = "";
        while(n--){
            s += "()";
        }
        return s;
    }
    vector<string> generateParenthesis(int n) {
        string s = gen(n);
        vector<string> final;
        set<string> ans;
        kev(0,s,ans);
        for(auto i: ans){
            if(valid(i))
            final.push_back(i);
        }
        return final;
    }
};

class Solution {
// this worked.
public:
    void kev(int open,int close,string ds,int n,vector<string> &ans){
      if(ds.size() ==n*2){
         ans.push_back(ds);
         return;
      }
      if(open<n){
         kev(open+1,close,ds+"(",n,ans);
      }
      if(close<open){
         kev(open,close+1,ds+')',n,ans);
      }
      
    }
vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        kev(0,0,"",n,ans);
        return ans;

    }
};
