class Solution {
// i guess my best dp attempt yet lol
public:
    int dp[1001][1001][2];
    int kev(int i,int prev , int pos,vector<int> a, int n){
        if(i == n){
            return 0;
        }

        if(dp[i][prev][pos] != 0){
            return dp[i][prev][pos];
        }

        int pick = 0;
        int not_pick = 0;

        if(prev < a[i] && !pos){
            prev = a[i];
            pos = 1;
            pick = 1 + kev(i + 1 , prev, pos ,a , n);
        }
        if(prev > a[i] && pos){
            prev = a[i];
            pos = 0;
            pick = 1 + kev(i + 1, prev, pos, a, n);
        }

        not_pick = 0 + kev(i + 1, prev, pos, a, n);

        return dp[i][prev][pos] = max(pick , not_pick);
    }

    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return 1;
        }
        memset(dp, 0, sizeof(nums.size())); 
        int prev = nums[0];
        int pos = nums[0] > nums[1];
        return kev(1 ,prev, pos, nums, nums.size()) + 1;
    }
};

class Solution{
// the perfect dp solution that didnt come to my mind.
// Here in the dp , we are doing recurison on difference , and not numbers.
// And i had doubts about the first initial value as well here after seeing this i am getting some ideas.
public:
    int solve(vector<int> &temp,vector<int> &dp,int ind, int prev,int n)
    {
        if(ind>=n)
            return 0;
        if(dp[prev+1]!=-1)
            return dp[prev+1];
        int take=0, nottake=solve(temp,dp,ind+1,prev,n);
        if(prev==-1 || (temp[prev]<0 && temp[ind]>=0) || (temp[prev]>=0 && temp[ind]<=0))
            take=1+solve(temp,dp,ind+1,ind,n);
        return dp[prev+1]=max(take,nottake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return n;
        vector<int> temp;
        for(int i=1;i<nums.size();i++)
        {
            int diff=nums[i]-nums[i-1];
            if(diff!=0)
                temp.push_back(diff);
        }
        vector<int> dp(n,-1);
        int size=temp.size();
        return 1+solve(temp,dp,0,-1,size);
    }
}
