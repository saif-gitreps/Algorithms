
class Solution {
// this failed at the last case
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        map<int, int> mp;
        
        for(int i = 0; i < d.size(); i++){
            mp[d[i]] = p[i];
        }

        int ans = 0;

        for(int i = 0; i < w.size(); i++){
            auto it = mp.begin();
            int mx = 0;
            
            while(it != mp.end() and it -> first <= w[i] ){
                mx = max(mx ,it -> second);
                it++;
            }
            
            ans += mx;
        }
        return ans;
    }
};

class Solution {
// ??? this worked, Okay i understood, i did not take that case into condiration where, we may have two or more jobs
// with same difficulty number but different profit level, so we want to make sure we the max of the bunch.
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        map<int, int> mp;
        
        for(int i = 0; i < d.size(); i++){
            mp[d[i]] = max(mp[d[i]], p[i]);
        }

        int ans = 0;

        for(int i = 0; i < w.size(); i++){
            auto it = mp.begin();
            int mx = 0;
            
            while(it != mp.end() and it -> first <= w[i] ){
                mx = max(mx ,it -> second);
                it++;
            }
            
            ans += mx;
        }
        return ans;
    }
};

class Solution {
public:
// better soln ig
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        map<int, int> mp;
        
        for(int i = 0; i < d.size(); i++){
            mp[d[i]] = p[i];
        }

        int ans = 0;

        for(int i = 0; i < w.size(); i++){
            auto it = mp.begin();
            int mx = 0;
            
            while(it != mp.end() and it -> first <= w[i] ){
                mx = max(mx ,it -> second);
                it++;
            }
            
            ans += mx;
        }
        return ans;
    }
};
