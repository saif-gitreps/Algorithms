class Solution {
public:
    // TLE for large number . 
    // need to figure out better way.
    bool isugly(int n){
        if(n==1){
            return true;
        }
        if(n==0){
            return false;
        }
        if(n%2==0) {return isugly(n/2);}
        if(n%3==0) {return isugly(n/3);}
        if(n%5==0) {return isugly(n/5);}
        return false;
    }
    int nthUglyNumber(int n) {
        long long count =0,i;
        for(i=1;i<=10000000000000000;i++){
            if(isugly(i)){
                count++;
            }
            if(count==n){
                break;
            }
        }
        return (int)i;
    }
};

class Solution {
//this is a better solution , theory explained here https://www.youtube.com/watch?v=kSDI_iOiGQY&ab_channel=KnowledgeCenter
public:
/*
what i understood from this is that , we hava table 
and all start from three pointers set to 0, one each for 2,3,5;
we first start by 2*1,3*1,5*1. here min is 2 . so two is first ugly, now we check if
the ugly we found is equal to min from all the ponter , then three increment that ugly pointer.
so on , will visit and try to solve this again .
*/
    int nthUglyNumber(int n) {
        vector<int> a(n+1);
        a[0] = 1;
        int index2=0;
        int index3=0;
        int index5=0;
        for(int i=1;i<=n;i++){
            int next2 = a[index2] * 2;
            int next3 = a[index3] * 3;
            int next5 = a[index5] * 5;
            int next = min({next2,next3,next5});
            if(next2 == next){
                index2++;
            }
            if(next3 == next){
                index3++;
            }
            if(next5 == next){
                index5++;
            }
            a[i] = next;
        }
        return a[n-1];
    }
};
