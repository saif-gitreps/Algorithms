class Solution {
// So i had similar Idea in mind, of using knapsack method.
// the problem with my implementation : I needed a copy of original needs array for not_pick, i didnt know how
// to do it other than creating a temp which itself was mess, but the solution was easy, just call not_pick before.

// the other idea was i mean i am looping through all the sp 2D array , why not just use i instead of a inner 
// recursive for loop.
public:
    int kev(int i,const vector<vector<int>> sp,const vector<int> pr, vector<int> n){
        if(i == sp.size()){
            int res = 0;
            for(int k = 0; k < n.size(); k++){
                res += (n[k] * pr[k]);
            }
            return res;
        }
        
        int pick = INT_MAX, not_pick = INT_MAX;
        not_pick =  kev(i + 1, sp, pr, n);
        
        for(int k = 0; k < n.size(); k++){
            n[k] -= sp[i][k];
            if(n[k] < 0){
                return not_pick;
            }
        }
        pick =  sp[i][n.size()] + kev(i, sp, pr, n);
    
        return min(pick, not_pick);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return kev(0, special, price, needs);
    }
};

class Solution {
// The previous solution showed TLE, tried the obvious way to memorize, shows wrong ans for 64th.
public:
    int kev(int i,const vector<vector<int>> sp,const vector<int> pr, vector<int> n, map<pair<int, vector<int>>, int> &dp){
        if(i == sp.size()){
            int res = 0;
            for(int k = 0; k < n.size(); k++){
                res += (n[k] * pr[k]);
            }
            return res;
        }

        if(dp.find({i, n}) != dp.end()){
            return dp[{i, n}];
        }
        
        int pick = INT_MAX, not_pick = INT_MAX;
        not_pick =  kev(i + 1, sp, pr, n, dp);
        
        for(int k = 0; k < n.size(); k++){
            n[k] -= sp[i][k];
            if(n[k] < 0){
                return not_pick;
            }
        }
        pick =  sp[i][n.size()] + kev(i, sp, pr, n, dp);
    
        return dp[{i, n}] = min(pick, not_pick);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<pair<int, vector<int>>, int> dp;
        return kev(0, special, price, needs, dp);
    }
};


class Solution {
// someone said to convert the array into string and now it works.
public:
    int kev(int i,const vector<vector<int>> sp,const vector<int> pr, vector<int> n, map<pair<int, string>, int> &dp){
        if(i == sp.size()){
            int res = 0;
            for(int k = 0; k < n.size(); k++){
                res += (n[k] * pr[k]);
            }
            return res;
        }

        string key = "";
        for(auto need : n){
            key += need;
        }

        if(dp.find({i, key}) != dp.end()){
            return dp[{i, key}];
        }

        int pick = INT_MAX, not_pick = INT_MAX;
        not_pick =  kev(i + 1, sp, pr, n, dp);
        
        for(int k = 0; k < n.size(); k++){
            n[k] -= sp[i][k];
            if(n[k] < 0){
                return not_pick;
            }
        }
        pick =  sp[i][n.size()] + kev(i, sp, pr, n, dp);
    
        return dp[{i, key}] = min(pick, not_pick);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<pair<int, string>, int> dp;
        return kev(0, special, price, needs, dp);
    }
};


class Solution {
// other way of doing it, i think my intuition was mix of both the solution, this was one was closer to what
// i had thought of, except without the base case part, and also fixes the confusion i had this temp array.
public:
    unordered_map<string, int> dp;
    int kev(int i,const vector<vector<int>> sp,const vector<int> pr, vector<int> n){
        int res = 0;
        for(int k = 0; k < n.size(); k++){
            res += (n[k] * pr[k]);
        }

        string key = to_string(i);
        for(auto need : n){
            key += need;
        }

        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        for(int j = i; j < sp.size(); j++){
            int flag = true;
            vector<int> temp;
            for(int k = 0; k < n.size(); k++){
                if(sp[j][k] > n[k]){
                    flag = false; break;
                }
                temp.push_back(n[k] - sp[j][k]);
            }
            if(flag){
                res = min(res, sp[j][n.size()] + kev(j, sp, pr, temp));
            }
        }
        return dp[key] = res;

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return kev(0, special, price, needs);
    }
};
