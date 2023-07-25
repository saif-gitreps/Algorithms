#include<iostream>

using namespace std;

int main(){
  int a;int b;
  cin>>a>>b;
  a = a ^ b; // a = 5^7. 
  b = b ^ a; // b = 7^(5^7) -> 7^7 cancels out, 5 remains.
  a = a ^ b; // a = (5^7)^5 [note:new value of b is 5 after line10] -> 5^5 cancels.
  cout<<a<<b;
}
