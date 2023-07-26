class Solution {
public:
    long long converter(string s){
        if(s.size()==0) return 0;
        long long ans= (s[s.size()-1]!='0');
        int k = 1;
        for(int i=s.size()-2;i>=0;i--){
            ans += ((s[i]-'0')*pow(2,k));
            k *= 2;
        }
        return ans;
    }
    void kev(int i,string s,string &ds,int &count){
        if(i>=s.size()){
            return;
        }
        if(ds.size()!=0 && ds[0]=='0'){
            return;
        }
        else{
            long long ans = converter(ds);
            if(ans==1 || ans==5){
                count++;
            }
            while(true){
                if(sqrt(ans)==5){
                    count++;
                    break;
                }
                if(sqrt(ans)<5){
                    break;
                }
                ans = sqrt(ans);
            }
        }
        for(int j = i;j < s.size(); j++){
            
                ds += s[j];
                kev(j+1,s,ds,count);
                ds.pop_back();
        
        }
    }
    int minimumBeautifulSubstrings(string s) {
        int count =0;
        string ds = "";
        kev(0,s,ds,count);
        if(count==0){
            return -1;
        }
        return count;
    }
};
