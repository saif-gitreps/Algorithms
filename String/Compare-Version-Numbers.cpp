class Solution {
public:
    int compareVersion(string ve1, string ve2) {
        string v1 = "";
        string v2 = "";
        for(int i = 0; i < ve1.size(); i++){
            if(i == 0 && ve1[i] == '0' ||
               i>0 && ve1[i-1] == '.' && ve1[i] == '0'){
                   while(i < ve1.size() && ve1[i] =='0'){
                       i++;
                       continue;
                   }
            }
            if(ve1[i] != '.') v1 += ve1[i]; 
        }
        for(int i = 0; i < ve2.size(); i++){
            if(i == 0 && ve2[i] == '0' ||
               i>0 && ve2[i-1] == '.' && ve2[i] == '0'){
                   while(i < ve2.size() && ve2[i] =='0'){
                       i++;
                       continue;
                   }
            }
            if(ve2[i] != '.') v2 += ve2[i]; 
        }
        return v1 == v2 ? 0 : (v1 > v2 ? 1 : -1);
    }
};
