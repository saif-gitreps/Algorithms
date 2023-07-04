class Solution {
public:
    int islandPerimeter(vector<vector<int>>& a) {
        int count = 0;
        int row = a[0].size();
        int col = a.size();
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(a[i][j]==1){
                    if(j-1<0){
                        count++;
                    }
                    if(j+1>=row){
                        count++;
                    }
                    if(i-1<0){
                        count++;
                    }
                    if(i+1>=col){
                        count++;
                    }
                    if((j-1>=0) && a[i][j-1]==0){
                        count++;
                    }
                    if(j+1<row && a[i][j+1]==0){
                        count++;
                    }
                    if((i-1>=0) && a[i-1][j]==0){
                        count++;
                    }
                    if((i+1<col) && a[i+1][j]==0){
                        count++;
                    }
                }
            }
        }
       return count;    
    }
};
