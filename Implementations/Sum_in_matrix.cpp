class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int mx = -1; int mx_index = 0;
        int sum = 0; int indx =0;
        for(int i=0;i<nums[0].size();){
            if(indx>=nums.size()){
                indx = 0;
            }
            mx_index = -1;
            mx = -1;
            vector<int> temp = nums[indx]; indx++;
            vector<int> deleting_arr;
            for(int j =0;j<temp.size();j++){
                if(temp[j]>mx){
                    mx = temp[j];
                    mx_index = j; 
                }
            }
            deleting_arr.push_back(mx_index);
            int final_mx = -1;
            if(indx==nums.size()){
                for(auto x: deleting_arr){
                    final_mx = max(final_mx,temp[x]);
                    temp[x] = -69;
                }
                i++;
                sum += final_mx;
            }
        }
        return sum;
    }
};
class Solution {
    //suiiiiiii , it worked , slow but it worked. hehe.
public:
    int matrixSum(vector<vector<int>>& nums) {
        int mx = -1; int mx_index = 0;
        int sum = 0; int indx =0;
        vector<int> deleting_arr;
        for(int i=0;i<nums[0].size();){
            if(indx>=nums.size()){
                indx = 0;
            }
            mx_index = -1;
            mx = -1;
            vector<int> temp = nums[indx]; 
            for(int j =0;j<temp.size();j++){
                if(temp[j]>mx){
                    mx = temp[j];
                    mx_index = j; 
                }
            }
            deleting_arr.push_back(mx_index);
            int final_mx = -1;
            if(indx==nums.size()-1){
                for(int k=0;k<deleting_arr.size();k++){
                    temp = nums[k]; 
                    final_mx = max(final_mx,temp[deleting_arr[k]]);
                    temp[deleting_arr[k]] = -69;
                    nums[k] = temp;
                }
                i++;
                deleting_arr = {};
                sum += final_mx;
            }
            indx++;
        }
        return sum;
    }
};