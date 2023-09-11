class Solution {
// complicated code, worked till 486/507.
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        //solving row by row.
        for(int i = 0 ; i < a.size() ; i ++){
            unordered_map<char,int> mp;
            for(int j = 0; j < a[0].size() ; j ++){
                if(mp[a[i][j]] == 1 && a[i][j]!='.'){
                    return false;
                }
                mp[a[i][j]] = 1;
            }
        }
        //solving column by column.
        for(int j = 0 ;j < a[0].size(); j++){
            unordered_map<char,int> mp;
            for(int i = 0; i < a.size(); i++){
                if(mp[a[i][j]] == 1 && a[i][j]!='.'){
                    return false;
                }
                mp[a[i][j]] = 1;
            }
        }
        int row = 1;
        int col = 1;
        for(int i = 1; i <= 9; i += 3){
            unordered_map<char,int> mp;
            if(i % 3 == 0){
               row = row + 3;
            }  
            for(int row_itr = row-1 ; row_itr < row+2; row_itr ++){
               for (int col_itr = col-1; col_itr < col+2; col_itr ++){
                  if(mp[a[row_itr][col_itr]] == 1 && a[row_itr][col_itr]!='.'){
                     return false;
                  }
                  mp[a[row_itr][col_itr]] = 1;
               }
            }
            col = col + 3;    
        }
        return true;

    }
};



class Solution {
// FINALLYYY FIGURED THE BULLSHIT OUT MY SELF.
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        //solving row by row.
        for(int i = 0 ; i < a.size() ; i ++){
            unordered_map<char,int> mp;
            for(int j = 0; j < a[0].size() ; j ++){
                if(mp[a[i][j]] == 1 && a[i][j]!='.'){
                    return false;
                }
                mp[a[i][j]] = 1;
            }
        }
        //solving column by column.
        for(int j = 0 ;j < a[0].size(); j++){
            unordered_map<char,int> mp;
            for(int i = 0; i < a.size(); i++){
                if(mp[a[i][j]] == 1 && a[i][j]!='.'){
                    return false;
                }
                mp[a[i][j]] = 1;
            }
        }
        int row = 0;
        int col = 0;
        while(true){
            unordered_map<char,int> mp;
            if(col == 9){
               row = row + 3;
               col = 0;
            }
            if(row == 9){
               break;
            }  
            for(int row_itr = row ; row_itr < row+3; row_itr ++){
               for (int col_itr = col; col_itr < col+3; col_itr ++){
                  if(a[row_itr][col_itr]!='.' && mp[a[row_itr][col_itr]] == 1){
                      return false;
                  }
                  else{
                    mp[a[row_itr][col_itr]] = 1;
                  }
               }
            }
            col = col + 3;   
        }
        return true;

    }
};



int isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    // optimal solution , lets dive deep
    
    int rows[9][9]={0}; //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
	int cols[9][9]={0}; //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
	int blocks[3][3][9]={0};//blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
	for(int r=0;r<9;r++)    //traverse board r,c
		for(int c=0;c<9;c++)
			if(board[r][c]!='.'){   //skip all number '.'
				int number=board[r][c]-'1'; //calculate the number's index(board's number minus 1)
				if(rows[r][number]++) return 0; //if the number has already appeared once, return false.
				if(cols[c][number]++) return 0;
				if(blocks[r/3][c/3][number]++) return 0;
			}
	return 1;
}
