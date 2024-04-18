class Solution {
// Need to combacke to this solution , and another one with tabulation.
public:
    int N, GOAL, K;
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    long long kev(int count_song, int count_unique){
        if(count_song == GOAL){
            if(count_unique == N){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[count_song][count_unique] != -1){
            return dp[count_song][count_unique];
        }

        long long ans = 0;

        if(count_unique < N){
            ans += (N - count_unique) * kev(count_song + 1, count_unique + 1);
        }

        if(count_unique > K){
        ans += (count_unique - K) * kev(count_song + 1, count_unique);         
        }

        return dp[count_song][count_unique] = ans % MOD;
    }


    int numMusicPlaylists(int n, int goal, int k) {
        N = n; GOAL = goal, K = k;
        dp.resize(goal + 1, vector<long long> (n + 1, -1));

        return kev(0, 0);        
    }
};
