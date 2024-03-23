// so basic idea is that , we have a starting base, then we take a pointer and move it accross the diagonal
// the solution https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/286753/c-with-picture/
// we take a trianlge, i , j , k and then do a recursion on the remaining portion that was outside the area of that
// trianle. God knows how poeple come up with the solution for these.
import (
    "fmt"
    "math"
)

func min(a int, b int) int {
    if a < b {
        return a;
    }
    return b;
}

var dp  [][]int;

func kev(i int, j int, a []int) int {
    if i+1 == j {
        return 0;
    }

    if dp[i][j] != -1{
        return dp[i][j]
    }

    ans := math.MaxInt32
    for k := i + 1; k < j; k++ {
        ans = min(ans, a[i]*a[j]*a[k]+kev(i, k, a)+kev(k, j, a));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

func minScoreTriangulation(values []int) int {
    n := len(values);

    dp = make([][]int, n);
    for i := range dp {
        dp[i] = make([]int, n);
        for j := range dp[i] {
            dp[i][j] = -1;
        }
    }

    return kev(0, n-1, values);
}
