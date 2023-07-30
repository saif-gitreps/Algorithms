#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#include<math.h>
#include<queue>
using namespace std;
https://codeforces.com/contest/706/problem/B

int bs_max(int a[],long long int x,int L,int R){
    int mid,ans=-1;
    int n = R;
    while(L<=R){
        mid = L + (R-L)/2;
        if(a[mid]>x){
            ans = mid;
           R = mid - 1;}
        else{
           L = mid + 1;}
      }
   if (ans != -1)
   return ans;
   else
   return n; }

int main (){
    int n;
    cin>>n;
    int a[100005] = {};
    for (int i =0;i<n;i++){cin>>a[i];}
    int q;
    cin>>q;
    long long int b[100005]={};
    sort(a,a+n);
    for(int i =0;i<q;i++) {
        cin>>b[i];
        cout<<bs_max(a,b[i],0,n)<<"\n";
    }
    }
