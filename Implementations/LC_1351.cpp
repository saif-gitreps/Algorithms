//1351. Count Negative Numbers in a Sorted Matrix
class Solution {
    // naive solution .
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0;int j=0;int count=0;
        while(i<grid.size()){
            if(grid[i][j]<0){
                count++;
            }
            j++;
            if(j+1>grid[i].size()){
                j=0;
                i++;
            }
        }
        return count;
    }
};