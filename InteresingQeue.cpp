#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
const int MAXN = 100005;
void solve(){
   queue<pair<int,int>> q;
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++){
      int pos;
      cin>>pos;
      q.push({pos,i});
      //here each pair is set in the queue, where i is the index or position.
   }
   while(true){
      if(q.size()==1){
         //this ends my confusion of how i would keep a queue and recognize the index possiton at the same time.
         cout<<q.front().second+1;
         break;
      }
      q.front().first -= m;
      //we first decrement the indices with m and next we check if they can go home.
      if(q.front().first<=0){
         q.pop();
      }
      else{
         //since they are not done, we will put the undone children in an index and back to the queue. 
         // note : q.pop() is necessary to avoid duplication.
         pair<int,int> p = q.front();
         q.pop();
         q.push(p);
      }
   }
}
 
int main(){
	ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  
   solve();
}
