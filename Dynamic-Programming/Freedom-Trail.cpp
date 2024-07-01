class Solution {
// first attempt, ofc overflow, my intuition was a bit jumbled.
public:
  int kev(int i, int n ,int j, string &r, string &k){
      if(j == k.size()){
          return 0;
      }
      debug(i);
      if(i == n || i == -1){
          return 0;
      }
      if(r[i] == k[j]){
          int clockwise = kev((i + 1), n, j + 1, r, k);
          int anticlockwise = kev((i + n -1), n , j + 1, r, k);
          return 1 + min(clockwise, anticlockwise);
      }
      else{
          int clockwise = kev((i + 1) % n, n, j, r, k);
          int anticlockwise = kev((i + n -1) % n, n , j, r, k);
          return 1 + min(clockwise, anticlockwise);
      }
  }
  int findRotateSteps(string ring, string key) {
       return kev(0, ring.size(), 0, ring, key);
  }

}

class Solution {
// very clean solution, i should start implementing loops in helper function for the things that 
// require searching instead of recursion calls, thats where I was stuck.
public:  
    int kev(int i, int j, string &r, string &k, vector<vector<int>> &dp){
        if(j == k.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(r[i] == k[j]){
            return dp[i][j] = 1 + kev(i, j + 1, r, k, dp);
        }
        int clock_wise = i;
        int aclock_wise = i;
        int cw_count = 0;
        int aw_count = 0;

        while(r[clock_wise] != k[j]){
            cw_count++;
            clock_wise = (clock_wise + 1) % r.size();
        }
        while(r[aclock_wise] != k[j]){
            aw_count++;
            aclock_wise = (aclock_wise + r.size() - 1) % r.size();
        }

        return dp[i][j] = min(
            kev(clock_wise, j + 1, r, k, dp) + cw_count + 1,
            kev(aclock_wise, j + 1, r, k, dp) + aw_count + 1
        );
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size(), vector<int> (key.size(), -1));
        return kev(0, 0, ring, key, dp);
    }
};


class Solution {
// solved after re visit.
public:
    vector<vector<int>> dp;
    int kev(int i, int j, string r, string k) {
        if (j == k.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int c_count = 0, ac_count = 0, c = i, a = i;

        while (k[j] != r[c]) {
            c = (c + 1) % r.size();
            c_count ++;
        }

        while (k[j] != r[a]) {
            a = (a + r.size() - 1) % r.size(); 
            ac_count++;
        }

        return dp[i][j] = min(
            c_count + 1 + kev(c, j + 1, r, k),
            ac_count + 1 + kev(a, j + 1, r, k)
        );
    }
    int findRotateSteps(string ring, string key) {
        dp.resize(ring.size() , vector<int> (key.size(), -1));
        return kev(0, 0, ring, key);
    }
};
