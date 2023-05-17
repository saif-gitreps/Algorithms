class Solution {
  //Check if All the Integers in a Range Are Covered
  // attempt 1.
public:
    bool isCovered(vector<vector<int>>& a, int left, int right) {
        int count =0;
        for(int i=0;i<a.size();i++){
            if(left!=-1){
                vector<int> sub;
                sub = a[i];
                if(sub[0]>=left){
                    count++;
                    left = -1;
                }
                else if(sub[1]>=left){
                    count++;
                    left = -1;
                }
            }
            if(right!=-1){
                vector<int> sub;
                sub = a[i];
                if(sub[0]>=right){
                    count++;
                    right = -1;
                }
                else if(sub[1]>=right){
                    count++;
                    right = -1;
                }
            }
        }
        return count==2;
    }
};
