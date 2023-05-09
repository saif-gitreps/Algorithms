class Solution {
  // test case passes 185/211
public:
    int maxDiff(int n) {
        string num = to_string(n);
        int mx = -1;
        for(int i=0;i<num.size();i++){
            string num2 = num;
            replace(num2.begin(),num2.end(),num2[i],'9');
            for(int j =0;j<num.size();j++){
                string num3 = num;
                replace(num3.begin(),num3.end(),num3[j],'1');
                int n1 = stoi(num2);
                int n2 = stoi(num3);
                int res = n1 - n2;
                mx = max(mx,res);
            }
        }
        return mx;
    }
};
