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

class Solution2 {
public:
    string addStrings(string num1, string num2) {
        int count = 0;
        int i=num1.size()-1,j=num2.size()-1;
        string newstr;
        while(i>=0 || j>=0 || count>0){
            if(i>=0){
                count += num1[i]-'0';
                i--;
            }
            if(j>=0){
                count += num2[j] - '0';
                j--; 
            }   
            newstr.push_back((count%10 + '0'));
            count /= 10;
        }
        reverse(newstr.begin(),newstr.end());
        return newstr;
    }
};

/*

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int main(){
	 string s;
	 cin>>s;
	 vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
      int values[] = {1000, 900, 500, 400, 100, 90, 50, 40,10,9,5,4,1};
     int num = 0;
     for(int i=0;i<s.size();i++){
         for(int j=0;j<13;j++){
             if(s[i]==roman[j]){
                 if(num<values[j]){
                      num = abs(num-values[j]);
                     }
                  else{
                      num = num + values[j];
                      }
                 }
             }
     }
     cout<<num;
}
*/