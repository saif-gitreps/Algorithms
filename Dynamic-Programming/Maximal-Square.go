// i could probably space optimize it but nah nvm.
// We are building the tabulation array by first finding a 2 x 2 square. If diagonally at the bottom right
// there is another square on top of it. Then we extend that square. 
//  https://www.youtube.com/watch?v=RElcqtFYTm0
func min(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func maximalSquare(matrix [][]byte) int {
    dp := make([][] int, len(matrix) + 1);
    for i := 0; i < len(dp); i++ {
        dp[i] = make([] int, len(matrix[0]) + 1);
        for j := 0; j < len(dp[i]); j++{
            dp[i][j] = 0;
        }
    }
    mx := 0;
    for i := 1; i < len(dp); i++ {
        for j := 1; j < len(dp[0]); j++ {
            if(matrix[i - 1][j - 1] == '1') {
                mn := min( dp[i - 1][j - 1], dp[i][j - 1] );
                dp[i][j] = 1 + min( mn, dp[i - 1][j] );
            }
            mx = max(dp[i][j], mx);
        }
    }
    return mx * mx;
}


// was able to spot out the intuition successfully

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> a(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));

        int mx = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[0].size(); j++) {
                if (i-1 >= 0 && j-1 >= 0 && matrix[i-1][j-1] == '1') {
                    a[i][j] =  1 + min(
                        a[i][j-1],
                        min(a[i-1][j], a[i-1][j-1])
                    );
                }
                mx = max(a[i][j], mx);
            }
        }

        return mx * mx;
    }
};
