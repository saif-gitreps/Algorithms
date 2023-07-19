class Solution {
public:
    bool is_safe(int col,int row,vector<string> board,int n){
        // so in checking if it is safe to place a queen 
        // we only have to check the top-left diagonal,left,bottom-left diagonal.
        int row_temp = row;
        int col_temp = col;
        //check top-left diagonal;
        while(row>=0 && col>=0){
            if(board[col][row]=='Q'){
                return false;
            }
            row--; col--;
        }
        //check only left;
        row = row_temp; col = col_temp;
        while(col>=0){
            if(board[col][row]=='Q'){
                return false;
            }
            col--;
        }
        row = row_temp;
        col = col_temp;
        //check bottom-left diagonal;
        while(row<n && col>=0){
            if(board[col][row]=='Q'){
                return false;
            }
            row++; col--;
        }
        return true; 
    }
    void kev(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(is_safe(col,row,board,n)==true){
                board[col][row] = 'Q';
                kev(col+1,board,ans,n);
                board[col][row] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<board.size();i++){
            board[i] = s; 
        }
        kev(0,board,ans,n);
        return ans;
    }
};


class Solution {
// best in terms of time complexity.
public:
    void kev(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &left_row,vector<int> &upper_diagonal,vector<int> &lower_diagonal,int n){
        // concept to rememeber about diagonal,
        // for checking lower diagonal and upper diagonal , keep a hash array of size
        // 2*n - 1. 
        // hash row + col for checking lower diagonal.
        // hash n-1 + (row-col);
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left_row[row]==0 && 
            lower_diagonal[row + col]==0 &&
            upper_diagonal[n-1 + (col - row)]==0){
                board[row][col] = 'Q';
                left_row[row] = 1;
                lower_diagonal[row+col] = 1;
                upper_diagonal[n-1 + (col - row)] = 1;
                kev(col+1,board,ans,left_row,upper_diagonal,lower_diagonal,n);
                board[row][col] = '.';
                left_row[row] = 0;
                lower_diagonal[row+col] = 0;
                upper_diagonal[n-1 + (col - row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<board.size();i++){
            board[i] = s; 
        }
        vector<int> left_row(n,0),upper_diagonal(2*n-1,0),lower_diagonal(2*n-1,0);
        kev(0,board,ans,left_row,upper_diagonal,lower_diagonal,n);
        return ans;
    }
};
