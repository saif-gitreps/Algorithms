class Solution {
// not working idk why shitty problem.
public:
    void dfs(int src, bool &atlantic, bool &pacific,int r, int c,const vector<vector<int>> h){ 
        if((r + 1 >= h.size() && c - 1 < 0) || (r - 1 < 0 && c + 1 >= h[0].size())){
            atlantic = true;
            pacific = true;
            return;
        }
        if(r - 1 < 0 || c - 1 < 0){
            pacific = true;
        }
        if(r + 1 >= h.size() || c + 1 >= h[0].size()){
            atlantic = true;
        }
        if(r < 0 || c < 0 || c == h[0].size() || r == h.size()){
            return;
        }

        if(r + 1 < h.size() && h[r + 1][c] <= src) 
            dfs(h[r + 1][c], atlantic, pacific, r + 1, c, h);
        if(r - 1 >= 0 && h[r - 1][c] <= src)    
            dfs(h[r - 1][c], atlantic, pacific, r - 1, c, h);
        if(c + 1 < h[0].size() && h[r][c + 1] <= src)
            dfs(h[r][c + 1], atlantic, pacific, r, c + 1, h);
        if(c - 1 >= 0 && h[r][c - 1] <= src)
            dfs(h[r][c - 1], atlantic, pacific, r, c - 1, h);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                bool atlantic = false, pacific = false;
                dfs(heights[i][j], atlantic, pacific, i, j, heights);
                if(atlantic && pacific){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
