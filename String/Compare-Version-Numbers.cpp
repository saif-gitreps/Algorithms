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


class Solution {
// Elegant solution , self explanatory. 
public:
    int compareVersion(string ve1, string ve2) {
   int i = 0;
   int j = 0;
   int n1 = ve1.size();
   int n2 = ve2.size();

   int num1 = 0;
   int num2 = 0;

   while(i < n1 || j < n2){
      while( i < n1 && ve1[i] != '.'){
         num1 = num1 * 10 + (ve1[i] - '0');
         i ++ ;
      }
      while( j < n2 && ve2[j] != '.'){
         num2 = num2 * 10 + (ve2[j] - '0');
         j ++;
      }

      if(num1 > num2 ) {
         return 1;
      }
      else if(num2 > num1 ){
         return -1;
      }
      num1 = 0;
      num2 = 0;
      // why i ++ and j ++ , because , we stopped at a fullstop.
      // next increment is other decimal digits.
      i++;
      j++;
   }
   return 0;           
}
};
