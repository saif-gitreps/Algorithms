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
