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
