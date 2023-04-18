class Solution1{
  // so the solution says that , those number with perfect square will be on,
  // so we need to count the number of perfect sqaures from 1-n;
  // but also it seems finding the root int of a number also gives us the number of 
  // perfect sqauares from 1-n. 
  
  public:  
    int bulb(int n){
    return sqrt(n);
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        int count;
        for(int i = 1; i*i<=n; i++){
            count++;
        }
        return count;
    }
};
