class Solution {
public:
  //NOTE : this simulation only for (n && m) < 4 .
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int n = matrix[0].size();
        int m = matrix.size();
        map<int,bool> hash;
        int i=0,j=0,k=0,limit = m*n;
        int stop = 0;
        while(limit>0){
            i = stop;
            j = stop;
            for(;j<n;j++){
                if(!hash[matrix[i][j]]){
                    hash[matrix[i][j]] = true;
                    nums.push_back(matrix[i][j]);
                    limit--;
                }
            }
            j--;
            for(;i<m;i++){
                if(!hash[matrix[i][j]]){
                    hash[matrix[i][j]] = true;
                    nums.push_back(matrix[i][j]);
                    limit--;
                }
            }
            i--;
            for(j=n-1-stop;j>=0;j--){
                if(!hash[matrix[i][j]]){
                    hash[matrix[i][j]] = true;
                    nums.push_back(matrix[i][j]);
                    limit--;
                    }
                 }
                j++;
            for(i=m-1-stop;i>=0;i--){
                    if(!hash[matrix[i][j]]){
                    hash[matrix[i][j]] = true;
                    nums.push_back(matrix[i][j]);
                    limit--;
                    }
                }      
            stop++;
        }     
    return nums;
    }
};

class Solution2 {
public:
  //this is a better solution. 
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int left = 0; int right = matrix[0].size()-1;
        int top = 0; int bottom = matrix.size()-1;
        int n = matrix[0].size() * matrix.size();
        while(nums.size()<n){
            for(int i=left;i<=right && nums.size()<n;i++){
                nums.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom && nums.size()<n;i++){
                nums.push_back(matrix[i][right]);
            }
            right--;
            for(int i= right;i>=left && nums.size()<n;i--){
                nums.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i=bottom;i>=top && nums.size()<n;i--){
                nums.push_back(matrix[i][left]);
            }
            left++;
        }

    return nums;}
};
