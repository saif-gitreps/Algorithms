class Solution {
// naive solution, easy nonetheless.
public:
    vector<vector<int>> dp;
    int kev(int i, int j, vector<int> &a){
        if(i > j){
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = max(
            a[i] + kev(i + 1, j, a),
            a[j] + kev(i, j - 1, a)
        );
    }
    bool stoneGame(vector<int>& a) {
        int sum = 0;
        for(auto n : a) sum += n;
        dp.resize(a.size(), vector<int> (a.size(), -1));

        int ans = kev(0, a.size() - 1, a);
        if(ans >= sum / 2){
            return true;
        }
        else{
            return false;
        }
    }
};

/*
  One thing about this problem is that , if given the condition that the sum is always odd
  and alice gets first chance , then alice always wins, 
  In the description, we know that sum(piles) is odd.
  If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
  If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.
  
  So, Alex always defeats Lee in this game.
  We can just return a simple true, that'll do it.
*/

// The neetcode solution decreases left by one and right by one.
// And in that Alice chooses if and only if len of array is even. and then return ans >= sum / 2.
