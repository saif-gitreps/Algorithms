class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        long long sum =0;
        int n = mat.size();
        if(n==1){
            //return mat[0][0];
        }
        for(int i=0;i<mat.size();i++){
            if(i==n-i-1){
                sum += mat[i][i];
            }
            else{
                sum += mat[i][i] + mat[i][n-i-1];
            }
        }
        return sum;
    }
};
