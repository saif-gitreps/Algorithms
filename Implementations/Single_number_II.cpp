class Solution {
  // this is O(n longn) and space O(1).
public:
    int singleNumber(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i+3<a.size();i+=3){
            if(a[i]==a[i+1] && a[i+1]==a[i+2]){
                continue;
            }
            else{
                if(a[i]!=a[i+1] && a[i]!=a[i+2]){
                    return a[i];
                }
                if(a[i+1]!=a[i] && a[i+1]!=a[i+2]){
                    return a[i+1];
                }
                if(a[i+2]!=a[i] && a[i+2]!=a[i+1]){
                    return a[i+2];
                }
            }
        }
        return a[a.size()-1];
    }
};
