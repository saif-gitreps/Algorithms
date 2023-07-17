class Solution {
// first attempt , passed till 168/170 cases. damn 
// second attempt, commented out that condition , and it passed but it was the slowest algorithm ever.
// third, added a break in the hash vector iterator.
// fourth, now i uncommented the condition , that made my code beat 80% in memeory but worse in time .
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
            if(count==((row+1)*(col+1))){
                break;
            }
            for(int j=0;j<row;j++){
                if(a[i][j]==0){
                    continue;
                }
                for(auto s: v){
                    if(s.first==i || s.second==j){
                        a[i][j] = 0;
                        count++;
                        break;
                    }
                }
            }
        }
        
    }
};

class Solution {
// O(n^2) time solution , with O(row+col) space  
public:
   void setZeroes(vector<vector<int>>& a) {
        int row = a[0].size();
        int col = a.size();
        int count = 0;
        vector<int> row_arr(row+1);
        vector<int> col_arr(col+1);
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(a[i][j]==0){
                    row_arr[j] = -1;
                    col_arr[i] = -1;
                }
            }
        }
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(col_arr[i]==-1){
                  a[i][j] = 0;
                }
                else if(row_arr[j]==-1){
                  a[i][j] = 0;
                }
            }
        }
        
    }
};
