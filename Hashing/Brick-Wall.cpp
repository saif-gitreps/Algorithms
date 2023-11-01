class Solution {
// The intuition is interesting.
// We bascially check all the gaps, and then then we increment it,
// After that we take the maximum gap there is and then -= the size or the number of rows.
// Why is that because , when you think about it , the more gaps we find in each row , the least brick we have to cut.
// If on the 4th gap we consistently get 5 gaps from 7 rows of brick ,then we only have to cut 2 bricks if we use the Gap number 4.
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        for(int i = 0; i < wall.size(); i++){
            int gap = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                gap += wall[i][j];
                mp[gap]++;
            }
        }
        int mx = 0;
        int mx_gap = 0;
        for(auto item: mp){
            if(item.second > mx){
                mx_gap = item.first;
                mx = item.second;
            }
        }
        return wall.size() - mx;    
    }
};


class Solution {
// optimized.
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int mx = 0;
        for(int i = 0; i < wall.size(); i++){
            int gap = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                gap += wall[i][j];
                mp[gap]++;
                mx = max(mp[gap], mx);
            }
        }
        return wall.size() - mx;    
    }
};
