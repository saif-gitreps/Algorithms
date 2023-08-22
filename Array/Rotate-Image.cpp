class Solution {
// first attempt , solved in 12 minutes, beats 32% in time , and sucked at memory
public:
    void rotate(vector<vector<int>>& a) {
        vector<vector<int>> temp;
        int col = a.size();
        int row = a[0].size();
        for(int j = 0; j < row; j ++){
            vector<int> new_row;
            for(int i = col-1;i>=0;i--){
                new_row.push_back(a[i][j]);
            }
            temp.push_back(new_row);
        }
        a = temp;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0 ; j < i; j++){
                swap(a[i][j],a[j][i]);
            }
        }
        for(int i =0 ; i < a.size(); i++ ){
            reverse(a[i].begin(),a[i].end());
        }
    }
};
