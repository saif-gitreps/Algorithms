//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> adj[], int vis[]){
        vis[node] = 1;
        
        for(auto child : adj[node]){
            if(vis[child] == 0){
                dfs(child, adj, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adj_list[V];
        int vis[V] = {0};
        for(int i = 0 ;i < V; i++){
            for(int j = 0 ; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                dfs(i, adj_list, vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
