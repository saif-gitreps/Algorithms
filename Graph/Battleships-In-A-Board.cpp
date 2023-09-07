class Solution {
public:
    int countBattleships(vector<vector<char>>& a) {
        int row = a.size();
        int col = a[0].size();
        if(row == 0 || col == 0){
            return 0;
        }
        int left,top;
        int ans = 0;
        for(int i = 0 ; i  < row ; i ++){
            top = i-1; // -1 means dealing with first index. 
            for(int j =0 ; j < col; j ++){
                left = j-1;
                if(a[i][j] == 'X'){
                    if((left < 0  || a[i][left] == '.') && (top < 0 || a[top][j] == '.')){
                        ans++;
                    }
                }
            }
        }
        return ans;        
    }

};
