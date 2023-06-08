class Solution {
    // ayyo ,this worked for 43 test cases baybee. whattta fuck.
public:
    bool check(int left,int right,vector<int> a,int p1,int p2){
        if(left==right){
            p1 += a[left];
            if(p1>=p2){
                return true;
            }
            return false;
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