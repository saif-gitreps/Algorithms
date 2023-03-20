#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// a greedy problem.
void solve(){
   int t,count = 0,i = 0,mark=0;
   ll sx,sy,ex,ey;
   cin>>t>>sx>>sy>>ex>>ey;
   string dir;
   cin>>dir;
   for(i=0;i<dir.size();i++){
      if(dir[i]=='N'){
         if((sy+1)<=ey)sy++;
      }
      else if(dir[i]=='S'){
         if((sy-1)>=ey)sy--;
      }
      else if(dir[i]=='W'){
         if((sx-1)>=ex)sx--;
      }
      else if(dir[i]=='E'){
         if((sx+1)<=ex)sx++;
      }
      if(sx==ex && sy==ey){
         cout<<i+1<<newline();
         return;
      }
   }
   cout<<-1;
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   solve();
}
 
