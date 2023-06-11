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

class Solution {
    // nLogn attempt , failed at 10 cases.
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0;int m=grid[0].size();int count=0;
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]<0){
                count+=m;
                continue;
            }
            else if(grid[i][m-1]>=0){
                continue;
            }
            int left = 0,right = m-1;
            int mid;
            while(left<=right){
                mid = (left+right)/2;
                if(mid-1>=0 && grid[i][mid]<0){
                    if(grid[i][mid-1]>=0){
                        break;
                    }
                }
                else if(grid[i][mid]>=0){
                    left = mid+1;
                }
                else{
                    right = mid;
                }
            }
            count += (m-mid);
        }
        return count;
    }
};

class Solution {
    // correct method , apparently BS will exit exactly on the negative number 
    // i didnt need any special methods.
    // on the code above the few lines before the bs is correct but idk why LC is showing more
    // time taken for it lmaooo.
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0;int m=grid[0].size();int count=0;
        for(int i=0;i<grid.size();i++){
            int left = 0, right = m - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (grid[i][mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        count += m - left;
        }
        return count;
    }
};