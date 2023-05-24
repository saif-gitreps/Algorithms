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

// [note:] interesting property  , the mod sum of two numbers 
// will be either the K or 0 (if two number are divisble)

class Solution {
    // this solution works, need to see it again.
public:
    bool canArrange(vector<int>& a, int k) {
           unordered_map<int,int> mp;
   // map still store each element's mod with the K
   // so what he explains is those numbers with mod 1
   // should be equal to the numbers that give mod 4
   // similarly those number whic have mod 2 should be 
   // equal number to mod 3 (for k=5)
   // if they are not equal , we have to return false. 
   for(int i=0;i<a.size();i++){
      int num = (a[i]%k+k)%k;
      // this is done to deal to with negative numbers.
      mp[num]++;
   }
   if(mp[0]%k==1){
      return false;
   }
   for(int i=1;i<k;i++){
      // this basically means count of 1%5(1)
      // == count of 4%5(4) i.e 1+4 == 5.
      // if that isnt equal then we print false.
      if(mp[i]!=mp[k-i]){
         return false;
      }
   }
   return true;

    }
};
