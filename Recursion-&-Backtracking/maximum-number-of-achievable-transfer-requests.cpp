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
