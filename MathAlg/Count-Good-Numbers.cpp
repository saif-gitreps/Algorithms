class Solution {
public:
    const int mod = 1e9 + 7;
    long long myPow(long long a, long long b) {
        if(b == 0){
            return 1;
        }

        long long ans = myPow(a, b / 2);
        ans *= ans;
        ans %= mod;

        if(b % 2 == 1){
            ans *= a;
        }
        ans %= mod;

        return ans;
    }
    int countGoodNumbers(long long n) {
      // intuition : for odd places , we can have a max 4 digits.
      // for even places we can have max 5 digits. if we want to find out the combination
      // we can do for example with 2 digits then. We know there are 1 even spot and 1 odd spot
      // The number of even odd combination with can do is 5^1 * 4^1. here for N = 2. one digit 
      // is for even, another digit is for odd. Also using a modified power algorithm.

        long long even = n/2 + n%2;
        long long odd = n/2;
        return ( myPow(5, even) * myPow(4, odd) )% mod;        
    }
};
