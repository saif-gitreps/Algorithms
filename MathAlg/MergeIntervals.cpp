class Solution {
public:
  // an overlap of interval is for example : {1,3} {2,4}.
  // here 3 and 2 have an overlap because we already finished 
  // traversing the point 3 but then again we have to go back to 2.
  // to have consistent flow , we remove a[i][1] and a[i+1][1]. and 
  // merge all the overlapping elements.
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        if(a.size()==1){
            return a;
        }
        vector<vector<int>> matrix;
        vector<vector<int>> temp = {a[0]};
        for(int i=1;i<n;i++){
            if(temp[0][1]>=a[i][0]){
                temp[0][1] = max(temp[0][1],a[i][1]);
            }  
            else{
               //debug(a[i][0]); debug(a[i][1]);
                matrix.push_back(temp[0]);
                temp[0] = a[i];   
            }
            if(i==n-1){
               //debug(temp[i][0]); debug(temp[i][1]);
               matrix.push_back(temp[0]);
            }
        }
        return matrix;
    }
};
