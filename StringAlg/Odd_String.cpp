#include <bits/stdc++.h>
/*             ::Pasteboard::
===========================================

===========================================
*/
using namespace std;

#define FAST(SUIII); ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAXN = 100010;

vector<int> find_factors(int n){vector<int> f;
for (int x=2;x*x<=n;x++)
{while(n%x==0) {f.push_back(x);n /= x;} }
if (n > 1) f.push_back(n);return f; }
/*==================================================*/

class Solution {
public:
   Solution(){

   }
    void oddString(vector<string>&& words) {
        map<vector<int>,int> m;
        vector<vector<int>> a;
        for(int i =0;i<words.size();i++){
            string temp = words[i];
            vector<int> b;
            for(int j=1;j<words[i].size();j++){
                int num = temp[j]-temp[j-1];
                b.push_back(num);
            }
            a.push_back(b);
            m[b]++;
        }
        string ans;
        for(int i=0;i<a.size();i++){
         debug(m[a[i]]);
            if(m[a[i]]==1){
               ans = words[i];
            }
        }
        cout<<ans;
    }
};
void solve(){
      Solution sol;

      sol.oddString({"aaa","bob","ccc","ddd"});

}

int main(){
   FAST(SUIII);
   //int t; cin>>t; while(t--)
   solve();
}



   









