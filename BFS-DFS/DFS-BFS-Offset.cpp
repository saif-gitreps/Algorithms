vector<int> offset = {0, 1, 0, -1, 0};

bool outOfBounds(int row, int col){
    return row < 0 || col < 0 || row > m -1 || col > n -1;
}

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int i, int j) {
   int m = matrix.size();
   int n = matrix[0].size();

   visited[i][j] = true;
   for (int k =1 ; k<offset.size(); k++){
       int row = i + offset[k], col = j + offset[k-1] ;
       if( !outOfBounds(row, col, m, n) && !visited[row][col] && matrix[row][col] >= maxtrix[i][j])
            dfs(matrix, visited, row, col);
   }
}
