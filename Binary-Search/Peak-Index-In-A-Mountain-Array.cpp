class Solution {
// easy problem but the only stupid thing missing was it was left = mid and not left = mid - 1;
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int mid;
        while(left <= right){
            
            mid = left + (right - left) / 2;

            if(mid - 1 >= 0 and mid + 1 < arr.size()){
                
                if(arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]){
                    return mid;
                }
                if(arr[mid - 1] < arr[mid] and arr[mid] < arr[mid + 1]){
                    left = mid;
                }
                else if(arr[mid - 1] > arr[mid] and arr[mid] > arr[mid + 1]){
                    right = mid;
                }
            }
        }
        return right;
    }
};
