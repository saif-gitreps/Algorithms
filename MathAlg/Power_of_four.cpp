class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1 || n==4){
            return true;
        }
        if(n%4!=0){
            return false;
        } 
        while(n){
            if(sqrt(n)==4){
                return true;
            }
            else{
                n /= 4;
            }
        }
        return false;
    }
};
