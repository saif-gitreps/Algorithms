// NOTE: i didnt submit this problem for now, Because the solution is not what i have come up with. But my intuition is kind of right.
// I kind of dont think this BS search , but i have to store this somewhere so YEA.
class Solution {
// first attempt, kind of works for 50cases/560 cases.
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<int> copy_array = nums;
        sort(copy_array.begin(),copy_array.end());
        //unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int left = 0;int right = nums.size()-1;
            int mid;
            while(left < right){
                mid = left + (right-left)/2;
                if(copy_array[mid] == nums[i]){
                    ans += abs(mid - i);
                    break;
                }
                else if(copy_array[mid] < nums[i]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return ans + nums.size();
    }
};
// so the best explanation i can write for this is that first we store the position of the all the elements.
// now here ans = n by default cuz even at the best case scenario you still have to remove N elements.
// so that this example -> A = [4,7,8,5,6,9]
// now this is the order by which elements should be removed i.e in hashing -> [0, 3, 4, 1, 2, 5].
// now the logic here is that if the indexes stored are in ascending order then its fine, 
// but lets say if they arent here in the case of 4th index, 4 > 1 , that means we have to perform a rotation , and by how much ?
// N - i is the rotation we have to perform. It doesnt matter if they sorted or no , we just have to make sure the indexes are in the ascending order.


long long countOperationsToEmptyArray(vector<int>& A) {
    unordered_map<int, int> pos;
    long long n = A.size(), res = n;
    for (int i = 0; i < n; ++i){
        pos[A[i]] = i;
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < n; ++i){
        if (pos[A[i]] < pos[A[i - 1]]){
            res += n - i;
        }
    }
    return res;
}
