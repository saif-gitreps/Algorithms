class Solution {
// best attempt date : 6 June 2023 , 55 / 65 cases
public:
    bool check(int left,int right,vector<int> a,int p1,int p2){
        if(a.size()==1){
                return true;
            }
        if(right-left==2 && a.size()%2!=0){
            if(a[left]+a[right]>a[left+1]){
                return true;
            }
            else{
                return false;
            }
        }
        if(right-left==1){
            if(p1+a[right]>=p2+a[left]){
                return true;
            }
            else if(p1+a[left]>=p2+a[right]){
                return true;
            }
            else{
                return false;
            }
        }
        bool checking1 = check(left+1,right-1,a,p1+a[left],p2+a[right]);
        bool checking2 = check(left+1,right-1,a,p1+a[right],p2+a[left]);
        return (checking1||checking2)? true:false;
    }
    bool PredictTheWinner(vector<int>& nums) {
    
        return check(0,nums.size()-1,nums,0,0);   
    }
};

class Solution {
// best recent attemp 45 /65 cases
public:
    int kev(int left, int right, vector<int> &a){
        if(left == right){
            return a[left];
        }
        if(left > right || left >= a.size() || right < 0){
            return 0;
        }
        int pick1 = 0;
        int pick2 = 0;
        if(a[left + 1] > a[right]){
            pick1 = a[left] + kev(left + 2, right, a);
        }
        else{
            pick1 = a[left] + kev(left + 1, right - 1, a);
        }

        if(a[left] > a[right - 1]){
            pick2 = a[right] + kev(left + 1, right - 1, a);
        }
        else{
            pick2 = a[right] + kev(left, right - 2, a);
        }

        return max(pick1, pick2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size() - 1, sum = 0;

        for(auto num : nums) sum += num;
        int result = kev(0, n, nums);

        if((double)result >= (double)sum / 2){
            return true;
        }
        return false;
    }
};


class Solution {
/*
  The player 1 intuition was right, either you pick from left or from right and maximize it
  But the player 2 intuition was wrong i think, i made it to maximise it for P2 as well.
  What i should have done is written the recursion to minimize the result for P2.
  In this problem we sort of are making 4 decisions. pick1 and pick2 for P1 and inner min() for p2.

  For p2 we are minimizing and for p1 we are maximizing.
*/
public:
    vector<vector<int>> dp;
    int kev(int left, int right, vector<int> &a){
        if(left == right){
            return a[left];
        }
        
        if(left > right || left >= a.size() || right < 0){
            return 0;
        }
        
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        
        int pick1 = 0;
        int pick2 = 0;
        
        pick1 = min(
            a[left] + kev(left + 2, right, a),        
            a[left] + kev(left + 1, right - 1, a)
        );
        
        pick2 = min( 
            a[right] + kev(left + 1, right - 1, a),
            pick2 = a[right] + kev(left, right - 2, a)
        );

        return dp[left][right] = max(pick1, pick2); 
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size() - 1, sum = 0;

        dp.resize(n + 1, vector<int> (n + 1, -1));

        for(auto num : nums) sum += num;
        int result = kev(0, n, nums);

        if(result >= sum - result)
            return true;
        return false;
    }
};
