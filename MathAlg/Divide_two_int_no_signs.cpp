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
