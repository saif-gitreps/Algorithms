class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i=a.size()-1;int j=b.size()-1,carry=0;
        while(i>=0 || j>=0){
            if(i<0){
                if(((b[j]-'0')+carry)==3){
                    carry=1;
                    ans+='1';
                }
                else if(((b[j]-'0')+carry)==2){
                    carry=1;
                    ans+='0';
                }
                else if(((b[j]-'0')+carry)==1){
                    carry=0;
                    ans+='1';
                }
                else{
                    carry=0;
                    ans+='0';
                }
                j--;

            }
            else if(j<0){
                if(((a[i]-'0')+carry)==3){
                    carry=1;
                    ans+='1';
                }
                else if(((a[i]-'0')+carry)==2){
                    carry=1;
                    ans+='0';
                }
                else if(((a[i]-'0')+carry)==1){
                    carry=0;
                    ans+='1';
                }
                else{
                    carry=0;
                    ans+='0';
                }
                i--;
            }
            else{
                if(((a[i]-'0')+(b[j]-'0')+carry)==3){
                    carry=1;
                    ans+='1';
                }
                else if(((a[i]-'0')+(b[j]-'0')+carry)==2){
                    carry=1;
                    ans+='0';
                }
                else if(((a[i]-'0')+(b[j]-'0')+carry)==1){
                    carry=0;
                    ans+='1';
                }
                else{
                    carry=0;
                    ans+='0';
                }
                j--;
                i--;
            }
        }
        if(carry){
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
