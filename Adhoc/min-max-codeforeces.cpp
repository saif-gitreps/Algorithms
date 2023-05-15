#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define enter_arr(x,n) for(int i=0;i<n;i++)cin>>x[i]
#define out_arr(x,n) for(int i=0;i<n;i++)cout<<x[i]<<" "
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

int main()
{
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   int l = max(a,c);
   int r = min(b,d);
   if(l<=r){
      cout<<l<<" "<<r<<endl;
   }
   else {
      cout<<-1;
   }
}
