// WTF its worked but 130+ lines lmaooo. I knew I had to reduce it.
func cellCount(board[][] int, i int, j int) []int{
    liveCells := 0;
    deadCells := 0;
    if (i - 1 >= 0){
        if(board[i - 1][j] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (j - 1 >= 0){
        if(board[i][j - 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (j + 1 < len(board[i])){
        if(board[i][j + 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (i + 1 < len(board)){
        if(board[i + 1][j] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (i + 1 < len(board) && j + 1 < len(board[i])){
        if(board[i + 1][j + 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (i + 1 < len(board) && j - 1 >= 0){
        if(board[i + 1][j - 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (i - 1 >= 0 && j - 1 >= 0){
        if(board[i - 1][j - 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    if (i - 1 >= 0 && j + 1 < len(board[i])){
        if(board[i - 1][j + 1] == 1){
            liveCells++;
        } else{
            deadCells++;
        }
    }
    res := []int{liveCells, deadCells}
    return res;
}

func cond1(board[][]int, i int, j int) bool{
    if(board[i][j] != 1){
        return false;
    }
    cellCounts := cellCount(board, i, j);
    if(cellCounts[0] < 2){
        return true;
    } 
    return false;
}
func cond2(board[][]int, i int, j int) bool{
    if(board[i][j] != 1){
        return false;
    }
    cellCounts := cellCount(board, i, j);
    if(cellCounts[0] == 2 || cellCounts[0] == 3){
        return true;
    }
    return false;
}
func cond3(board[][]int, i int, j int) bool{
    if(board[i][j] != 1){
        return false;
    }
    cellCounts := cellCount(board, i, j);
    if(cellCounts[0] > 3){
        return true;
    }
    return false;
}
func cond4(board[][]int, i int, j int) bool{
    if(board[i][j] != 0){
        return false;
    }
    cellCounts := cellCount(board, i, j);
    if(cellCounts[0] == 3){
        return true;
    }
    return false;
}

func gameOfLife(board [][]int)  {
    // doing the brute force way.
    temp := make([][]int, len(board));
    for i := range (board) {
        temp[i] = make([]int, len(board[i]));
    }

    for i := range board {
        for j := range board[i] {
            if(cond1(board, i, j)){
                temp[i][j] = 0;
            } else if (cond2(board, i, j)){
                temp[i][j] = 1;
            } else if (cond3(board, i, j)){
                temp[i][j] = 0;
            } else if (cond4(board, i, j)){
                temp[i][j] = 1;
            } 
        }
    }
    for i := range board {
        for j := range board[i] {
            board[i][j] = temp[i][j];
        }
    }
}

// Second attempt. This solution is much better and condensed.

func cellCounts(board[][] int, i int, j int) int{
    liveCells := 0;
    comb := [][]int{{-1, -1},{0, -1},
                    {-1, 1}, {-1, 0},
                    {0, 1}, {1, -1},
                    {1, 0}, {1, 1}, };

    for k := 0; k < 8; k++ {
        r := i + comb[k][0];
        c := j + comb[k][1];
        if(r >= 0 && r < len(board) && c >= 0 && c < len(board[i])){
            if(board[r][c] == 1){
                liveCells++;
            }
        }
    } 
    return liveCells;
}

func gameOfLife(board [][]int)  {
    temp := make([][]int, len(board));
    for i := range (board) {
        temp[i] = make([]int, len(board[i]));
    }

    for i := range board {
        for j := range board[i] {
            liveCells := cellCounts(board, i, j);
            
            if (board[i][j] == 1){
                if (liveCells < 2){
                    temp[i][j] = 0;
                
                } else if (liveCells == 2 || liveCells == 3){
                    temp[i][j] = 1;
                
                } else if (liveCells > 3){
                    temp[i][j] = 0;
                }
            } else{
                if(liveCells == 3){
                    temp[i][j] = 1;
                }
            }
        }
    }
    for i := range board {
        for j := range board[i] {
            board[i][j] = temp[i][j];
        }
    }
}
