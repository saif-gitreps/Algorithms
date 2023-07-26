class Solution {
public:
    bool detectCapitalUse(string a) {
        if(a.size()==1)
            return true;
        int cap=0;
        bool first= false;
        if (a[0]>=65 && a[0]<=91){
            first = true;
            cap++;
        } 
        for(int i=1;i<a.size();i++){
            if(a[i]>=65 && a[i]<=91)
                cap++;
        }
        if(cap==a.size()){
            return true;
        }
        else if(cap==0){
            return true;
        }
        else if(cap==1 && first==true){
            return true;
        }
           return false;
    }
};
