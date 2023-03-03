#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline() "\n"
#define nexline() std::cout<<newline()
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
#define GGG 9223372036854775807
#define pb push_back
#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        double def = n;
        if(n<0){
            n = abs(n);
        }
        while(n>0){
        if(n%2==1){
            res *= x;
            }
            x *= x;
            n /= 2;
        }
        if(def<0){
            res = 1/res;
        }
        return res;
    }
};

void solve(){
   double a;
   int n;
   cout<<myPow(a,n);
}

int main(){
   FAST(SUIII);
   int t;cin>>t;while(t--)
   solve();
}

