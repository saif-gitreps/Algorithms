class Solution {
public:
  // my soln , beat 90% .
    bool sign(string c){
        if(c=="+") return true;
        if(c=="-") return true;
        if(c=="/") return true;
        if(c=="*") return true;
        return false;
    }
    int cal(int a,int b,string sign){
        if(sign=="+"){
            return a+b;
        }
        if(sign=="-"){
            return a-b;
        }
        if(sign=="/"){
            return a/b;
        }
        if(sign=="*"){
            return a*b;
        }
        return NULL;
    }
    int evalRPN(vector<string>& a) {
        stack<int> s;
        for(int i =0 ;i<a.size();i++){
            if(sign(a[i])==false){
                int num = 0;
                string number = a[i];
                if(number[0]=='-'){
                    for(int k=1;k<number.size();k++){
                    int dig = number[k]-48;
                    num = num*10 + dig;
                    }
                    num = num*-1;                       
                }
                else{
                    for(int k=0;k<number.size();k++){
                        int dig = number[k]-48;
                        num = num*10 + dig;
                    }
                }
                s.push(num);
            }
            else if(sign(a[i])){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                int res = cal(num2,num1,a[i]);
                s.push(res);
            }
        }
        return s.top();
    }
};
