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

class Solution {
/* optimal solution:
We got 3 matrix map and one 3D matrix map for hashing.
From my code i realised i didnt need 2 difference traversal of row and column , we could just do the same in one traversal.
Now for the edge case of inner block.

row/3 and col/3 means that imagine the first first from left , its index is on a[0][0] -> a[2][2] for example
. now row/3 and col/3 means 0/3 is 0 and 2/3 is also 0 , so the first block from left is at index 00 .
the rest are:
00 01 02
10 11 12
20 21 22

in block[][][] <- this third index is used to hash all the numbers from 00 sub block, if it exists then we can return false.

*/
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        int row_check[9][9] = {0};
        int col_check[9][9] = {0};
        int block[9][9][9] = {0};

        for(int row = 0 ; row < 9; row ++){
            for(int col = 0; col < 9; col ++){
                if(a[row][col]=='.'){
                    continue;
                }
                int num = a[row][col] - '1';
                if(row_check[row][num]++ || col_check[col][num]++ || block[row/3][col/3][num]++){
                    return false;
                }
            }
        }
        return true;
    }
};
