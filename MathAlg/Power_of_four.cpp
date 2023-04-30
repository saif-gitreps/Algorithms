class Solution {
public:
    // attemp1
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
class Solution2 {
public:
    // atempt 2
    bool isPowerOfFour(int n) {
        if(n==1 || n==4){
            return true;
        }
        if(n%4!=0 || n<4){
            return false;
        }
        while(n){
            if(sqrt(n)==4 || n==4){
                return true;
            }
            n = n>>4;
        }
        return false;
    }
};

Class solution3{
public:
    bool CheckFour(int num){
        if(num<1){
        return false;
        }
        int n = num , count = 0;
        while(n){
            n>>=2;
            count += 2;
        }
        return (n<<count)==num;
    }
    
};
