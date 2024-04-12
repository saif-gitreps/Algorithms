class Solution {
public:
    int mx(vector<vector<int>> &a, int start){
      int total = -1;
      for (auto p : a){
        if(p[0] <= start){
          int diff = p[1] - start;
          total = max(diff , total);
        }
      }
      
      return total;

    }

    int videoStitching(vector<vector<int>>& clips, int time) {
      int curr = 0;
      int most = mx(clips, curr);
      int count = 0;
      
      while (curr < time and most > 0){
        curr += most; count++;
        most = mx(clips, curr);
      }
        
      return curr >= time ? count : -1; 
    }
};