class Solution {
// i did the bruteforce  backtracking method, it showed TLE , i have to use greedy instead
public:
    bool check(string s){
        if(s.size()<3){
            return true;
        }
        for(int i= 0 ; i < s.size()-2; i ++){
            if(s[i] == 'a' && s[i+1] == 'a'  && s[i+2] == 'a'){
                return false;
            }
            else if(s[i] == 'b' && s[i+1] == 'b'  && s[i+2] == 'b'){
                return false;
            }
        }
        return true;
    } 
    string ans = "";
    void kev(int a,int b,int n,string &ds){
        if(ds.size()>=(n)){
            if(check(ds)){
                ans = ds;
            }
            return;
        }
        if((ds.size()==0 && a>=1) || a>=1){
            ds+="a";
            kev(a-1,b,n,ds);
            ds.pop_back();
        }
        if((ds.size()==0 && b>=1) || b>=1){
            ds+="b";
            kev(a,b-1,n,ds);
            ds.pop_back();
        }
    }
    string strWithout3a3b(int a, int b) {
        string ds = ""; 
        kev(a,b,a+b,ds);
        return ans;
    }
};
