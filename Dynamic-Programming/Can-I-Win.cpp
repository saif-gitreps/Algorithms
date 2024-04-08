class Solution {
// personal best attempt 45/70 cases.
public:
    vector<vector<int>> dp;
    bool kev(int turn, int sum, int mc, int dt, vector<int> options){
        if(sum >= dt){
            return turn == 1;
        }

        if(dp[sum][turn] != -1){
            return dp[sum][turn];
        }

        
        for(int i = 1 ; i <= mc; i++){
            if(options[i]){
                if(turn == 1){
                    options[i] = 0;
                    return dp[sum][turn] = kev(2, sum + i, mc, dt, options);
                    options[i] = 1;
                }
                else{
                    options[i] = 0;
                    return dp[sum][turn] = kev(1, sum + i, mc, dt, options);
                    options[i] = 1;
                }
            }
        }
        
        return dp[sum][turn] = false;
    }
    bool canIWin(int mc, int dt) {
        if(mc >= dt){
            return true;
        }
        
        vector<int> options(mc + 1, 1);
        dp.resize(dt + 1,vector<int> (3, -1));

        return kev(1, 0, mc, dt, options);

    }
};

class Solution {
// best attempt at dp.
public:
    vector<int> dp;
    bool kev(int sum, int mc, vector<int> options){
        if(sum <= 0){
            return false;
        }

        if(dp[sum] != -1){
            return dp[sum];
        }
        
        for(int i = 1 ; i <= mc; i++){
            if(options[i]){
                options[i] = 0;
                if(!kev(sum - i, mc, options)){
                    dp[sum] = true;
                    options[i] = 1;
                    return true;
                }
                options[i] = 1;
            }
        }
        
        return dp[sum] = false;
    }
    bool canIWin(int mc, int dt) {
        if(mc >= dt){
            return true;
        }
        
        vector<int> options(mc + 1, 1);
        dp.resize(dt + 1, -1);

        return kev( dt, mc, options);

    }
};

class Solution {
// GOT TLE , someone said i need to use bitmask or something.
public:
    unordered_map<string, int> dp;
    bool kev(int sum, int mc, vector<int> &options){
        if(sum <= 0){
            return false;
        }

        string key = "";
        for(auto opt : options){
            key += (opt + '0');
        }

        if(dp.count(key)){
            return dp[key];
        }
        
        for(int i = 1 ; i <= mc; i++){
            if(options[i]){
                options[i] = 0;
                if(!kev(sum - i, mc, options)){
                    dp[key] = true;
                    options[i] = 1;
                    return true;
                }
                options[i] = 1;
            }
        }
        
        return dp[key] = false;
    }
    bool canIWin(int mc, int dt) {
        if(mc >= dt){
            return true;
        }

        if(((1 + mc) / 2 * mc) < dt)
            return false;
        
        vector<int> options(mc + 1, 1);

        return kev(dt, mc, options);

    }
};