class Solution {
// first attempt , passed till 168/170 cases. damn 
// second attempt, commented out that condition , and it passed but it was the slowest algorithm ever.
public:
    void setZeroes(vector<vector<int>>& a) {
        int row = a[0].size();
        int col = a.size();
        int count = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(a[i][j]==0){
                    v.push_back({i,j});
                    count++;
                }
            }
        }
        for(int i=0;i<col;i++){
            // if(count==((row+1)*(col+1))){
            //     break;
            // }
            for(int j=0;j<row;j++){
                if(a[i][j]==0){
                    continue;
                }
                for(auto s: v){
                    if(s.first==i || s.second==j){
                        a[i][j] = 0;
                        count++;
                    }
                }
            }
        }
        
    }
};
