class Solution {
public:
    string addStrings(string num1, string num2) {
        string newstr;
        int rem = 0;
        int first=num1.size()-1,second=num2.size()-1;
        while(first>=0 || second>=0){
            if(first<0){
               int num = ((num2[second]- '0') + rem);
               newstr.push_back(num%10+'0');
               rem = num/10;
               second--; 
            }
            else if(second<0){
               int num = ((num1[first]-'0') + rem);
               newstr.push_back(num%10+'0');
               rem = num/10;
               first--;
            }
            else{
               int num = ((num1[first]-'0') + (num2[second]-'0') + rem);
               newstr.push_back(num%10+'0');
               rem = num/10;
               first--; second--;  
            }  
        }
        if(rem>0){
            newstr.push_back(rem+'0');
        }
        reverse(newstr.begin(),newstr.end());
      return newstr;
    }
};
