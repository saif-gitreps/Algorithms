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


class Solution {
// HAHA just implemented quick sort logic , it worked. SUI.
public:
    int party_boy(vector<vector<int>>& a, int k,int start, int end){
        int pivot = a[end][k];
        int i=start,j=end;
        int pindex = start;
        for(int i = start; i < end; i++){
            if(a[i][k] > pivot){
                vector<int> temp = a[i];
                a[i] = a[pindex];
                a[pindex] = temp; 
                pindex++;
            }
        }
        vector<int> temp = a[pindex];
        a[pindex] = a[end];
        a[end] = temp;
        return pindex;
    }

    void quicky_boy(vector<vector<int>>& a, int k, int left,int right){
        if(left < right){
            int partition_index = party_boy(a, k, left, right);
            quicky_boy(a, k, left, partition_index - 1);
            quicky_boy(a, k, partition_index + 1, right);    
        }
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& a, int k) {
        quicky_boy(a, k , 0, a.size()-1);
        return a;
    }
};
