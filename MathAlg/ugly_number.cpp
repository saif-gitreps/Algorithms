class Solution {
public:
  // note my solution works but it is the worst solution.
    vector<int> factors(int n){
        vector<int> facts;
        for(long long i=2;i*i<=n;i++){
            while(n%i==0){
                facts.push_back(i);
                n/=i;
            }
        }
        if(n>1){ facts.push_back(n);}
        return facts;
    }

    bool isUgly(int n) {
        if(n==1) return true;
        vector<int> fact = factors(n);
        if(fact.size()==0){return false;}
        for(int i=0;i<fact.size();i++){
            if(fact[i]>5){
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
 // optimized solution.
public:
    bool isUgly(int n) {
        if(n==1) return true;
        if(n==0) return false;
        if(n%2==0){
          return isUgly(n/2)
        }
        if(n%3==0){
          return isUgly(n/3)
        }
        if(n%5==0){
          return isUgly(n/5)
        }
        return 0;
    }
};
