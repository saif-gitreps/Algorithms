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
