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
//using dp and memoeization 

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


//====================================================================================
//haha solved it on my own , idk if it was the right solution or no.

int ninjaTraining(int n, vector<vector<int>> &a){   
    vector<vector<int>> dp(n ,vector<int> (4, -1));
    for(int last = 0; last < 3 ; last ++){
        int mx = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                mx = max(a[0][i] , mx);   
            }
        }
        dp[0][last] = mx;
    }
    int final_mx = 0; 
    for(int i = 1; i < n; i++){
        for(int  last = 0; last < 3; last++){
            int mx = 0;         
            for(int k = 0; k < 3 ;k ++){
                int pts;
                if( k != last){
                pts = a[i][k] + dp[i-1][k];
                mx = max(pts,mx);
                }   
            }
            dp[i][last] = mx;
            // typically the last answer or the final best optimal solution will be stored in the last index.
            // so i chose the best possible result from any of the last index results.
            if(i == n-1){
                final_mx = max(dp[i][last],final_mx);
            }
        }
    }
    return final_mx;
}


//==============================================================================
//striver's code:

int ninjaTraining(int n, vector<vector<int>> &a){   
    vector<vector<int>> dp(n ,vector<int> (4, -1));
    dp[0][0] = max(a[0][1] ,a[0][2]);
    dp[0][1] = max(a[0][0] ,a[0][2]);
    dp[0][2] = max(a[0][0] ,a[0][1]);
    dp[0][3] = max(a[0][0] ,max(a[0][1],a[0][2]));
    for(int i = 1; i < n; i++){
      for(int  last = 0; last < 4; last++){         
         for(int k = 0; k < 3 ;k ++){
            int pts;
            if( k != last){
               pts = a[i][k] + dp[i-1][k];
               dp[i][last] = max(pts ,dp[i][last]);
            }   
         }
      }
   }
//so here the third index helps us find the maximum optimal solution from each points. and we basically store it in the third index. 
   return dp[n-1][3];
}

//=====================================================================================
//such pretty code.
//space complexity is O(4) which is as good as O(1) anyway.
//So the pattern is that , once you are able to find the top - down approach ,  u can easily convert it into a bottom - up approach
//From there its easy to just implement space optimization.

int ninjaTraining(int n, vector<vector<int>> &a){   
   vector<int> prev(4,0);
   prev[0] = max(a[0][1],a[0][2]);
   prev[1] = max(a[0][0],a[0][2]);
   prev[2] = max(a[0][0],a[0][1]);
   prev[3] = max(a[0][0] ,max(a[0][1],a[0][2]));

   int final_mx = 0; 
   for(int i = 1; i < n; i++){
      vector<int> curr(4 , 0);          
      for(int  last = 0; last < 4; last++){
         for(int k = 0; k < 3 ;k ++){
            int pts;
            if( k != last){
               pts = a[i][k] + prev[k];
               curr[last] = max(pts ,curr[last]);
            }   
         }
      }
      prev = curr;
   }
   return prev[3];
}

    
