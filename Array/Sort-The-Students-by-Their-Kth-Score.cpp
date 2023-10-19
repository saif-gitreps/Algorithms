class Solution {
// Navie solution. works tho.
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& a, int k) {
        for(int i = 0 ; i < a.size() - 1; i++){
            vector<int> temp;
            for(int j = i + 1; j < a.size(); j++){
                if(a[i][k] < a[j][k]){
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp; 
                }
            }
        }
        return a;
    }
};
