class Solution {
// attempt 1. idk why all i get is 9.
public:
    bool complete(vector<vector<char>>& a){
         int count = 0 ;
         for(int row = 0; row < 9; row ++ ){
            for(int col = 0 ; col < 9; col ++ ){
                if(a[row][col] == '.'){
                  count++;
                }
            }
         }
         return count==0?true:false;
    }
    bool check(vector<vector<char>> &a){
        int row_check[9][9] = {0};
        int col_check[9][9] = {0};
        int block[9][9][9] = {0};
        for(int row = 0; row < 9; row ++ ){
            for(int col = 0 ; col < 9; col ++ ){
                if(a[row][col] == '.'){
                    continue;
                }
                int num = a[row][col] - '1';
                if(row_check[row][num]++ ||
                   col_check[col][num]++ ||
                   block[row/3][col/3][num]++ 
                ){
                    return false;
                }
            }
        }
        return true;
    }
    void kev(vector<vector<char>>& a,int row,int col){
       if(check(a) == false){
           return;
       }
       for(int i = row; i < 9; i++ ){
           for(int j = col; j < 9; j++){
               if(a[i][j] == '.'){
                   for(int num = 1 ; num <= 9 ; num++ ){
                       a[i][j] = num + '0';
                       kev(a,i,j);
                   }
               }
           }
       }
    }
    void solveSudoku(vector<vector<char>>& board) {
        kev(board,0,0);
    }
};
