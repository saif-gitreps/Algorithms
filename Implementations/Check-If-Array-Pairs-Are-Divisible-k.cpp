class Solution {
    //attempt 1 : got hit by TLE .
public:
    bool canArrange(vector<int>& a, int k) {
        int left = 0,count =0;
        int right = a.size()-1;
        int mx = -INT_MAX;
        while(left<=right){
            if(left==right){
                if(abs(a[left])%k==0){
                    count++;
                }
            }
            else if((abs(a[left])+abs(a[right]))%k==0){
                count++; left++; right--;
                mx = max((abs(a[left])+abs(a[right])),mx);
            }
            else if((abs(a[left])+abs(a[right]))%k!=0 && (abs(a[left])+abs(a[right]))<mx){
                left++;
            }
            else if((abs(a[left])+abs(a[right]))%k!=0 && (abs(a[left])+abs(a[right]))>mx){
                right--;
            }
        }
        if(count==(a.size()/2)){
            return true;
        }
        else{
            return false;
        }
    }
};