class Solution {
public:
    bool isugly(int n){
        if(n==1){
            return true;
        }
        if(n==0){
            return false;
        }
        if(n%2==0) {return isugly(n/2);}
        if(n%3==0) {return isugly(n/3);}
        if(n%5==0) {return isugly(n/5);}
        return false;
    }
    int nthUglyNumber(int n) {
        long long count =0,i;
        for(i=1;i<=10000000000000000;i++){
            if(isugly(i)){
                count++;
            }
            if(count==n){
                break;
            }
        }
        return (int)i;
    }
};
