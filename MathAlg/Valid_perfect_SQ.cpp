class Solution {
public:
    bool square(int l,int r,int num){
        long long  mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid>num){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
    bool isPerfectSquare(int num) {
        return square(0,num,num);
        
    }
};

class Solution2 {
public:

    bool isPerfectSquare(int num) {
        int x=0;
        for(;x<=num;x++){
            if(x>INT_MAX/10){
                return false;
            }
            else if(pow(x,2) == num)
            return true;
        }
        return false;
    }
};

class Solution23 {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
          return true;
        for(long long int i=1;i<=num/2;i++)
            if(i*i==num)
               return true;
        return false;
    }
};
