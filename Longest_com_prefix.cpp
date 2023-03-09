class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        string newstr = "";
        int i=0,j=0,count=0;
        char first = a[0][0];        
        while(true){
            if(a[i][j]=='\0'){
                break;
            }
            if(a[i][j]==first){
                count++;
            }
            if(count==a.size()){
                newstr += first;
            }
            if(i==a.size()-1){
                if(count!=a.size()){
                    break;
                }
                i = 0;
                count =0;
                ++j;
                first = a[0][j];
            }
            else{
                i++;
            }
        }
    return newstr;}
  // as you can see mine is , a very complicated algorithmn.
};

class Solution2 {
public:
  // this is a smart solution .
  // in short sentences , he only compares the sorted form of last and first .
  // why is that cuz theres where you will find the largest alphabetic diff.
  // so an unmatched string over first and last equals to the longest for the rest of the array as well.
    string longestCommonPrefix(vector<string>& strs) {
         int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};
