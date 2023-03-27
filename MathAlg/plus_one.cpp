class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int n = a.size();
        for(int i = n-1; i>=0; i-- ){
            if(i==n-1){
                a[i]++;
            }
            if(a[i]==10){
                a[i] = 0;
                if(i!=0){
                    a[i-1]++;
                }
                else{
                  // if this condition activates that means all the numbers are 9 and therefore we will have a 0 at the end anyway.
                    a.push_back(0);
                    a[i] = 1;
                }
            }
        }
    return a;}
};
