class Solution {
public:
  // naive solution, does not work for large input.
    int divide(int a, int b) {
        int i = 0;
        bool a_negative = false,b_negative =false;
        if(a<0){
            a = abs(a);
            a_negative = true;
        }
        if(b<0){
            b = abs(b);
            b_negative = true;
        }
        while(a>0){
            a -= b;
            i++;
         }
        if(a==0){
            if(a_negative && b_negative){
                return i;
            }
            else if(a_negative || b_negative){
                return -(i);
            }
            return i;
        }
        else{
            if(a_negative && b_negative){
                return i-1;
            }
            else if(a_negative || b_negative){
                return -(i-1);
            }
            return (i-1);
        }
    }
};

class solution2{
public:
  // optimal solution , although i dont understand the solution , will revisit. 
    int division(int divident,int divisor){
          if(divident==divisor) return 1;
          bool sign = (divident>0)==(divisor>0) ? true:false;
          unsigned int a = abs(divident);
          unsigned int b = abs(divisor);
          unsigned int res = 0;
          while(a >= b) {
              short count =0;
              while( a > (b<<count+1)){
                count++;
              }
              res += 1<<count;
              a -= b<<count;
          }
          if(res==1<<32 && sign){
              return INT_MAX:
          }
          return sign? res:-res;
    }
  
};
