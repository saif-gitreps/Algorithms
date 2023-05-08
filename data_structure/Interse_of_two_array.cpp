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
