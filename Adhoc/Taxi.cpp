#include<iostream>
    #include<cstring>
    #include<string>
    #include<algorithm>
    #include<vector>
    #include<set>
    #include<math.h>
    //my best attempt at this problem.
    using namespace std;
        int main(){
        int n,num,count=0,taxi=0; 
        cin>>n; 
        int a[100000] = {0};
        int digit[5] = {0};
        for(int i =0;i<n;i++){ 
        cin>>a[i]; digit[a[i]]++; }
        count += (digit[3]+digit[4]);
        if(digit[3]<digit[1] && digit[3]>0){
            count += ceil((double)(digit[1]+digit[3]*3)/4);
            }
        else if(digit[1]>=digit[2] && digit[2]%2!=0){
            count += ceil((double)(digit[1]+digit[2]*2)/4);
            }
        else if(digit[2]>0 && digit[1]==0 || digit[1]%2==0){
             count += ceil((double)(digit[2]*2)/4);
            }
       if(digit[1]>0 && (digit[2]==0 && digit[3]==0) || (digit[2]%2==0 && digit[3]==0)){
        count += ceil((double)digit[1]/4);}
        cout<<count;
    //===============================//
        return 0;}
