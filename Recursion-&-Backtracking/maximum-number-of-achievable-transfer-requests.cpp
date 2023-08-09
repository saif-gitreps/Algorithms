class Solution {
private:
//so it is a pick me and not pick me method , i didnt know i could do that,
//i was focused on a graph approach which would have been interesting.
public:
    int ans = 0;
    void kev(int i,vector<vector<int>> &a,vector<int> &ds,int count){
        if(i>=a.size()){
            for(int k=0;k<ds.size();k++){
                if(ds[k]!=0){
                    return;
                }
            }
            ans = max(ans,count);
            return;
        }
        ds[a[i][0]]--;
        ds[a[i][1]]++;
        kev(i+1,a,ds,count+1);
        ds[a[i][0]]++;
        ds[a[i][1]]--;
        kev(i+1,a,ds,count);
        
    }
    int maximumRequests(int n, vector<vector<int>>& a) {
        vector<int> ds(n);
        kev(0,a,ds,0);
        return ans;
    }
};


=============================================================================
#include <bits/stdc++.h>
    //naive attempt , the concept was there i just wished i knew i had to use backtracking bruteforces
using namespace std;
const int N = 1e5 + 10;
vector<vector<int>> g(N);
vector<bool> visit(N);
vector<int> level(N);

int maximumRequests(int n, vector<vector<int>>& a) {
        vector<int> buildings(n,0);
        for(int i=0;i<a.size();i++){
            buildings[a[i][0]]--;
            buildings[a[i][1]]++;
        }
        int count =0;
        for(int i=0;i<buildings.size();i++){
            debug(buildings[i]);
            if(buildings[i]==0){
                count++;
            }
        }
        return count;
    }

int main() {
    vector<vector<int>> v = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};

    cout<<maximumRequests(5,v);

    return 0;
}
 
