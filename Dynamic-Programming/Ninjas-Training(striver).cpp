https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//The recursive solution (raw bruteforce solution).
int kev(int n, int last,vector<vector<int>> a){
    if(n == 0){
        int mx = 0;
        for(int i = 0; i < 3; i++){
            if( i != last){
                mx = max(mx,a[n][i]);
            }
        }
        return mx;
    }
    int mx = 0;
    for(int i = 0 ; i < 3 ; i ++){
        int points = 0;
        if (i != last) {
            points = a[n][i] + kev(n - 1, i, a);
        }
        mx = max(points,mx);
    }
    return mx;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return kev(n-1 , 3, points);
}

//========================================================================
using dp and memoeization 

int kev(int n, int last,vector<vector<int>> &a,vector<vector<int>> &dp){
    if( dp[n][last] != -1){
        return dp[n][last];
    }
    if(n == 0){
        int mx = 0;
        for(int i = 0; i < 3; i++){
            if( i != last){
                mx = max(a[0][i],mx);
            }
        }
        return dp[n][last] = mx;
        
    }
    int mx = 0;
    for(int i = 0 ; i < 3 ; i ++){
        if (i != last) {
            int point = a[n][i] + kev(n - 1, i, a ,dp);
            mx = max(point,mx);
        }
    }
    // why last , because , i want to know what will be the max value that i can get if 
    // i have chosen or passed this sub index. So the recursion finds it out for me.
    // IN simple word , if my examples last choice was index 0 , what is the maximum value
    // the recurstion will bring it for me if i had chosen that index . And once i get that ans
    // i store it in my "last choice" index.
    return dp[n][last] = mx;
}

int ninjaTraining(int n, vector<vector<int>> &points){   
    vector<vector<int>> dp(n , vector<int>(4 , -1));
    return kev(n-1 , 3, points, dp);
}
