class Solution {
// idk the bruteforce worked. Not the best but atleast it worked.
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        vector<int> ans;
        
        for(auto interval : a){
            int mn = INT_MAX, mn_index = -1;
            for (int i = 0; i < a.size(); i++) {
                if (a[i][0] >= interval[1]) {
                    if (a[i][0] < mn) {
                        mn = a[i][0];
                        mn_index = i; 
                    }
                }
            }

            ans.push_back(mn_index);
        }

        return ans;
    }
};


class Solution {
// Damn , i found the better solution on my own, even though i took like more than an hour. 
// Could use sorting but at the same time you need a copy of some sort, better to just use map
// knowing that map sorts the element, also we need to store the index.
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        vector<int> ans;
        map<int, int> mp;

        for(int i = 0 ; i < a.size(); i++){
            mp[a[i][0]] = i; 
        }

        for(auto interval : a){
            auto it = mp.lower_bound(interval[1]);
             
            if (it == mp.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};
