class Solution1 {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> ans;
   map<int,int> m;
   for(int i=0;i<a.size();i++){
      m[a[i]]++;
   }
   for(int i=0;i<b.size();i++){
      if(m[b[i]]>0){
         ans.push_back(b[i]);
         m[b[i]] = 0;
      }
   }
   return ans;
    }
};
class Solution2 {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> ans;
    set<int> s;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j]){
                s.insert(a[i]);
            }
        }
    }
    for(auto x: s){
        ans.push_back(x);
    }
    return ans;
    }
};

class Solution3 {
public:
    // apparently using undoreded map is much faster.
    vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> ans;
   unordered_map<int,int> m;
   for(int i=0;i<a.size();i++){
      m[a[i]]++;
   }
   for(int i=0;i<b.size();i++){
      if(m[b[i]]>0){
         ans.push_back(b[i]);
         m[b[i]] = 0;
      }
   }
   return ans;
    }
};
