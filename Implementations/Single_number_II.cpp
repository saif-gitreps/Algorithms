class Solution {
  // this is O(n longn) and space O(1).
public:
    int singleNumber(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i+3<a.size();i+=3){
            if(a[i]==a[i+1] && a[i+1]==a[i+2]){
                continue;
            }
            else{
                if(a[i]!=a[i+1] && a[i]!=a[i+2]){
                    return a[i];
                }
                if(a[i+1]!=a[i] && a[i+1]!=a[i+2]){
                    return a[i+1];
                }
                if(a[i+2]!=a[i] && a[i+2]!=a[i+1]){
                    return a[i+2];
                }
            }
        }
        return a[a.size()-1];
    }
};

class Solution2 {
  // i dont really understand the solution.
  // refer https://www.youtube.com/watch?v=cOFAmaMBVps&t=59s&ab_channel=Techdose 
public:
    int singleNumber(vector<int>& a) {
        int one =0;
        int two =0;
        for(auto num: a){
            one = (one^num) & (~two);
            two = (two^num) & (~one);
        }
        return one;
    }
};
