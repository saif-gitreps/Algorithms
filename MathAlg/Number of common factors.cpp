class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 1;
        int big = max(a,b);
        int sma = min(a,b);
        for(int i=2;i<=big;i++){
            if(big%i==0 && sma%i==0){
                count++;
            }
        }
        return count;
    }
};
class Solution {
    // note : this doesnt work,but i like the concept and the idea .
public:
    vector<int> factors(int n,int m){
        vector<int> a;
        for(int i=2;i*i<=n && i*i<=m;i++){
            while(n%i==0 && m%2==0){
                a.push_back(i);
                n = n/i;
                m = m/i;
            }
        }
        if(n==m && n>1){
            a.push_back(n);
        }
        return a;
    }
    int commonFactors(int a, int b) {
        int i=0,j=0,count = 1;
        if(max(a,b)%min(a,b)==0){
            count++;
        }
        vector<int> v = factors(a,b);
        count += v.size();
        return count;
    }
};
