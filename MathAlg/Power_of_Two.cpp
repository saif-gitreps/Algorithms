class Solution {
public:
  // similar solution to power of four.
    bool isPowerOfTwo(int num) {
        if(num<1){
            return false;
        }
        int n = num , count = 0;
        while(n>1){
            n>>=1;
            count++;
        }
        return n<<count==num;
    }
};
