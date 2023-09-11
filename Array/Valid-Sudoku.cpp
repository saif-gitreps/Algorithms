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
