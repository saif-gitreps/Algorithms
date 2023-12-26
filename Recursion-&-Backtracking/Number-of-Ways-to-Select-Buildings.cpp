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



class Solution {
//Base condition is when we either have picked 3 buildings, or else we have reached end of string.
//Note : We are assuming that if no building is picked, then prev = 2.
//Our changing variables are prev, len, and index. prev being a tracker for the last picked item.
public:
    long long dp[100003][3][4];    
    long long kev(int i, int prev, int len, string &s){
        if(len == 3){
            return 1;
        }
        if(i == s.size()){
            return 0;
        }
        if(dp[i][prev][len] != -1){
            return dp[i][prev][len];
        }
        long long ans = 0;
        ans = kev(i + 1, prev, len , s);
        if(prev != s[i] - '0'){
            ans += kev(i + 1, s[i] - '0' , len + 1, s);
        }
        return dp[i][prev][len] = ans;
    }

    long long numberOfWays(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return kev(0, 2, 0, s);
        //return dp[n-1][2][0];
    }
};
