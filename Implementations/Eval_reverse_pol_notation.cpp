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
//this is a java sol that i really liked.
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String s : tokens) {
            if ("+".equals(s)) stack.push(stack.pop() + stack.pop());
            else if ("-".equals(s)) stack.push(-stack.pop() + stack.pop());
            else if ("/".equals(s)) stack.push((int)(1D / stack.pop() * stack.pop()));
            else if ("*".equals(s)) stack.push(stack.pop() * stack.pop());
            else stack.push(Integer.valueOf(s));
        }

        return stack.pop();
    }
class Solution3 {
  //compact solution.
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        for (const std::string& token : tokens) {
            if (std::isalnum(token[0]) || token.size() > 1) {
                int x = std::stoi(token);
                s.push(x);
            } else {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                int z = 0;
                switch (token[0]) {
                    case '+': z = x + y; break;
                    case '-': z = x - y; break;
                    case '*': z = x * y; break;
                    default: z = x / y; break;
                }
                s.push(z);
            }
        }
        return s.top();
    }
};

// interesting solution

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};
