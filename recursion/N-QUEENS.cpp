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
