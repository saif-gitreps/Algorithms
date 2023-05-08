class Solution {
  // i dont understand what is happening.
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> res;
        backtracking(bits,res,n);
        return res;
    }
    void backtracking(bitset<32>& bits, vector<int>& res,int k){
        if(k==0){
            res.push_back(bits.to_ulong());
            return;
        }
        backtracking(bits, res, k-1);
        bits.flip(k-1);
        backtracking(bits, res, k-1);
    }
};

class Solution {
  // i uderstood the thoery little bit.
public:
    vector<int> grayCode(int n) {
       vector<int> ans;
       ans.push_back(0);

       if(n==0) return ans;
       ans.push_back(1);
       int current  = 1 ;
       for(int i=2;i<=n;i++){
           current *= 2;
           for(int j = ans.size()-1;j>=0;j--){
               ans.push_back(current+ans[j]);
           }
       }
       return ans;
    }
};
