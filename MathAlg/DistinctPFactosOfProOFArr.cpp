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

class Solution2 {
public:
  // this worked , difference is that.
  // we used the algorithm to find the prime factos of each elements
  // instead of product of array, and even that seems to give us accruate prime factors.
    int distinctPrimeFactors(vector<int>& nums) {
        long long n = 1;
        set<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                while(nums[i]%j==0){
                    v.insert(j);
                    nums[i]/=j;
                }
            }
            if(nums[i]>1){
                v.insert(nums[i]);
            }
        } 
        return v.size();
    }
};
