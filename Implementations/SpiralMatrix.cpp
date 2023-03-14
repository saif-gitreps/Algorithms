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
