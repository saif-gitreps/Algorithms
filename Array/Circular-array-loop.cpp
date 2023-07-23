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


//====================================
class Solution {
// the proper solution , i understood what the solution wanted.
public:
int next(vector<int> &a,int curr,bool isForward){
    int n = a.size();
    bool direction = a[curr]>=0;
    //this checks if the next dir is not 
    //going on the same path as our
    //graph is getting travesered to.
    
    if(direction!=isForward){
        return -1;
    }
    int ans = (curr+a[curr])%n;
    if(ans<0){
        ans += n;
    }
    //we dont accept self loops.
    if(ans==curr){
        return -1;
    }
    return ans;
}
    bool circularArrayLoop(vector<int>& a) {
    int n = a.size();
    if(n<=1){
        return false;
    }
    for(int i=0;i<n;i++){
        int slow=i,fast=i;
        int isForward = a[i]>=0;
        while(true){
            slow = next(a,slow,isForward);            if(slow==-1){
                break;
            }
            fast = next(a,fast,isForward);
            if(fast==-1){
                break;
            }
            fast = next(a,fast,isForward);
            if(fast==-1){
                break;
            }
            if(fast==slow){
                return true;
            }
        }    
    }
    return false;
    }
};

