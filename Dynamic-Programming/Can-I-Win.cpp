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

class Solution {
public:
    /*
    According to the code above, the players are alternating turns.
    This means first players is the 1st one to call the method helper 
    then second player turn comes then the first player again and so on.

    We are trying all the possibilities for each player in order for him/her to win.

    Let's assume a test case:
    2
    2

    First Player chooses 1
    Second Player find that 1 is taken, so (s)he chooses 2
    First Player turn find that desiredTotal <= 0, so the helper method return false
    Second Player receives this false with a ! before it, so the helper method return true
    First Player finds that after choosing 1, he received a true from the helper method, 
    this means, choosing 1 will make second player win and him lose

    First Player unchoose 1 and chooses 2
    Second Player find that desiredTotal <= 0, so the helper method return false
    First Player receives this false with a ! before it, so the condition is true now 
    and Player 1 Wins.

    Now we cant use sum as a key because there is a chance of duplication or same 
    sum situation happening so we have to use a hashing key that is unique but also
    recurring to memoize and one of them would be by using the options array
    we use the array to bring out a unique number using this bit masking algorithm
    */
    unordered_map<int, int> dp;
    bool kev(int sum, int mc, vector<int> &options){
        if(sum <= 0){
            return false;
        }

        int key = 0;
        for(auto opt: options){
            key <<= 1;
            if(!opt){
                key |= 1;
            }
        }
        key = (int)key;

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