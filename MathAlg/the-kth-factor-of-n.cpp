class Solution {
// first attempt , solved in 3 mins.
public:
    int kthFactor(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                v.push_back(i);
            }
        }
        if(k>v.size()){
            return -1;
        }
        for(int i=0;i<v.size();i++){
            if(i==k-1){
                return v[i];
            }
        }
        return -1;
    }
};
