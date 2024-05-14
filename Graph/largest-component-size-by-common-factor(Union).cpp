class Solution {
// Naive BFS attemp, doesnt work. 30/100 cases.
public:
    int dfs(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        int mx = 1;
        for(auto child : adj[src]){
            if(!vis[child]) {
                mx = max(mx, 1 + dfs(child, adj, vis));
            }
        }
        return mx;
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && __gcd(nums[i], nums[j]) > 1){
                    adj[i].push_back(j);
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n ; i++) {
            vector<int> vis(n, 0);
            mx = max(mx, dfs(i, adj, vis));
        }

        return mx;
    }
};

class Solution {
// This one works but TLE at 74.
// idea is by using DSU, We will make a union if they both have a common gcd > 1.
// then return the max size of each parent node.
public:
    vector<int> parent;
    vector<int> size;

    void Make(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v){
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return;
        }
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            Make(i);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && __gcd(nums[i], nums[j]) > 1){
                    Union(i, j);
                }
            }
        }
        int mx = 1;
        for(int i = 0; i < n ; i++) {
            mx = max(mx, size[i]);
        }

        return mx;
    }
};


class Solution {
// Just like how 2 is related to 3 if there exist 6 in the array because, 2 - > 6 and 3 -> 6. therefor
// 2 <-> 6 <->  3. That also means 2, 3 and 6 has the same factors. So here the Set will contain parent
// of the common factor. we first make a union of Number and its divisor, and then number with the quotient.
// example 20 % 10 == 0, 20 and 10 is one Set, and 20 and 2 is another set.
// In the final calculation, We find the parent of every element in the array i.e , the common factor
// or the root which connects all the elements and find the max of it. Like here among 2, 3, 6. All 
// of them will have 2 as the common factor and the root under which 2 , 3 and 6 are there. So ans is 3.
public:
    vector<int> parent;
    vector<int> size;

    int find(int v){
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void Union(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a == b){
            return;
        }
        if(size[a] > size[b]){
            parent[b] = parent[a];
            size[a] += size[b];
        }
        else{
            parent[a] = parent[b];
            size[b] += size[a];
        }
    }

    int largestComponentSize(vector<int> nums) {
        int n = nums.size();

        int max_len = 0;
        for(int i = 0; i < n; i++){
            max_len = max(max_len, nums[i]);
        }
        parent.resize(max_len + 1);
        for(int i = 0; i < max_len + 1; i++){
            parent[i] = i;
        }
        size.resize(max_len + 1, 1);
        
        for(auto num : nums) {
            for(int i = 2; i <= sqrt(num); i++){
                if(num % i == 0){
                    Union(num, i);
                    Union(num, num / i);
                }
            }
        }
        int mx = 1;
        unordered_map<int, int> mp;
        for(int i = 0; i < n ; i++) {
            int parent = find(nums[i]);
            mp[parent]++;
            mx = max(mx, mp[parent]);
        }

        return mx;
    }
};
