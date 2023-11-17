class Solution {
// IDK , naive attempt, worked tho.
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        multiset<int> s;
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                s.insert(a[i][j]);
            }
        }
        multiset<int>::iterator it = s.begin();
        int ans;
        while(k > 1){
            k--;
            it++;
        }
        return *it;
    }
};


class Solution {
// using maxheap or priority queue.
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        priority_queue<int> pq;
        for(int i = 0 ; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                pq.push(a[i][j]);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};


class Solution {
// gives TLE at the last 2 edge cases.
//[update : changed the mid formula , it worked]
public:
    int count(vector<vector<int>> &a, int k, int mid){
        int cnt = 0;
        int r = a.size();
        int c = a[0].size();
        // this method reduces TC.
        int j = c - 1;
        for(int i = 0 ; i < r; i++){
            for(j ; j >= 0; j--){
                if(a[i][j] <= mid){
                    cnt += (j + 1);
                    break;
                }
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& a, int k) {
        int r = a.size();
        int c = a[0].size();

        int left = a[0][0];
        int right = a[r-1][c-1];

        while(left < right){
            int mid = floor((right - left)/2 + left);
            int cnt = count(a, k, mid);
            if(cnt >= k){
                right = mid;  
            }
            else{
                left = mid + 1;
            }
        }
        return left;

    }
};
