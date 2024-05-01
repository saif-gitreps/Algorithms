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
