#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#define debug(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<"\n"
//tried something.
using namespace std;

bool trav(vector<int> &a,int i,vector<int> &mp){
    if(mp[i]==true){
        return true;
    }
    
    
    if(i>=a.size()){
        return false;
    }
    if(mp[i]==true){
        return true;
    }
    mp[i] = true;
    trav(a,a[i],mp);
    mp[i] = false;    
}

int neg_index(int curr,int n,int k){
    int ans = (curr+k)%n;
    if(ans<0){
        ans += n;
    }
    return ans;
    }

void solve(){
    vector<int> a = {2,-1,1,2,2};
    int n = a.size();
    vector<int> graph(n,-1);
    for(int i=0;i<n;i++){
        int pos;
        if(a[i]<0){
            pos = neg_index(i,n,a[i]);   
        }
        else if(a[i]+i<n){
            pos = a[i]+i;
            debug(a[i]+i); 
        }
        else{
            pos = (a[i]+i)%n;
            debug(pos);
        }
        graph[i] = pos;
    }
    for(int i=0;i<n;i++){
        //cout<<graph[i]<<" ";
        }
    vector<int> mp(n,-1);
    cout<<trav(graph,0,mp);
}

int main(){
    solve();     	 	 	 	
     	 	 	 	 	 	
}
