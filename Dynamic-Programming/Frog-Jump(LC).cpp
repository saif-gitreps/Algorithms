class Solution {
// this attempt worked for 12/50 cases.
public:
    bool kev(int i,int k, vector<int> a){
        if(i == a.size()-1){
            if(k + a[i-1] == a[i]){
                return true;
            }
            return false;
        }
        // if(i >= a.size()){
        //     return false;
        // }
        int x = false;
        int y = false;
        int z = false;
        for(int j = i+1; j < a.size(); j++){
            if(k + a[i] == a[j]){
                x = kev(j , k , a);
            }
            if((k+1) + a[i] == a[j]){
                y = kev(j , k + 1 , a);
            }
            if((k-1) + a[i] == a[j]){
                y = kev(j , (k - 1) , a);
            }
        }
        return (x || y || z);
    }
    bool canCross(vector<int>& stones) {
        return kev(1, 1, stones);
    }
};


class Solution {
// 14/50 now , i think this will go on from test case to test case.
// UPDATE , i missed sending a Z , sent 2 Ys.
// successfully reached the TLE case, now time to memoize.
public:
    bool kev(int i,int k, vector<int> a){
        if(i >= a.size()){
            return false;
        }
        if(i == a.size()-1){
            // if(k + a[i-1] == a[i] ||
            //   (k+1) + a[i-1] == a[i] ||
            //   (k-1) + a[i-1] == a[i] ){
            //     return true;
            // }
            return true;
        }
        int x = false;
        int y = false;
        int z = false;
        for(int j = i+1; j < a.size(); j++){
            if(k + a[i] == a[j]){
                x = kev(j , k , a);
            }
            if((k+1) + a[i] == a[j]){
                y = kev(j , k + 1 , a);
            }
            if((k-1) + a[i] == a[j]){
                z = kev(j , (k - 1) , a);
            }
        }
        return (x || y || z);
    }
    bool canCross(vector<int>& stones) {
        return kev(0, 0, stones);
    }
};
