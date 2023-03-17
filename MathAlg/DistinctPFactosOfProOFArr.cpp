class Solution1 {
public:
  // marked at integer overflow on 56th test case / 75.
    set<int> prime_factors(long long n){
        set<int> v;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                v.insert(i);
                n/=i;
            }
        }
        if(n>1){
            v.insert(n);
        }
        return v;
    }
    int distinctPrimeFactors(vector<int>& nums) {
        long long n = 1;
        for(int i=0;i<nums.size();i++){
            n *= nums[i];
        }
        set<int> v = prime_factors(n); 
        return v.size();
    }
};
