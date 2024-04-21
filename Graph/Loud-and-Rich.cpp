class Solution {
// The description was horrible, The first yt video explained it so well, and implemented the code on my own.
// https://www.youtube.com/watch?v=2VQftGT1gCQ
//The solution revolves around making the graph and then the goal is to find the quietest (i.e the person with the least quiet value)
// among the graph relation. this is a very naive implementation.

// [Very important to note: in a graph, if something is lesser than something then that means it is pointing to it]
// example: if 0 is lesser than 1,that means 0 -> 1. If A is greater than B then our graph relation is B -> A.

public:
    int dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> quiet){
        vis[src] = 1;
        int mn = quiet[src];

        for(auto child : adj[src]){
            if(!vis[child]){
                mn = min(mn, dfs(child, adj, vis, quiet));
            }
        }

        return mn;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        unordered_map<int, int> mp;

        for(int i = 0 ; i < richer.size(); i ++){
            int x = richer[i][1];
            int y = richer[i][0];
            adj[x].push_back(y);
        }

        for(int i = 0; i < n; i ++){
            mp[quiet[i]] = i;
        }

        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            int mn = dfs(i, adj, vis, quiet);
            ans.push_back(mp[mn]);
        }

        return ans;
    }
};

class Solution {
// more spaced optimized version of my solution.
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int size = quiet.size();
        vector<vector<int>> graph(size);
        vector<int> ans(size, -1);
        // Constructs Graph
        for (auto rich : richer) {
            graph[rich[1]].push_back(rich[0]);
        }
        // Run DFS for each person on Graph
        for (int i = 0; i < size; i++) {
            dfs(graph, quiet, ans, i);
        }
        return ans;
    }

    int dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<int> &ans, int currentPerson) {
        // Check and return whether if the answer is already calculated or not
        if (ans[currentPerson] >= 0) {
            return ans[currentPerson];
        }
        // Save at least person's value itself in case that no richer and least loud person found in search
        ans[currentPerson] = currentPerson;
        for (auto child : graph[currentPerson]) {
            if (quiet[dfs(graph, quiet, ans, child)] < quiet[ans[currentPerson]]) {
                ans[currentPerson] = ans[child];
            }
        }
        return ans[currentPerson];
    }
};

class Solution {
// TRYING HARD BUT STILL CANT UNDERSTAND THE TOPO SORT SOLN.
// update , i made the graph the opposite way which confused the F outta me.
// here the graph was made with 0 <- 1 , instead of 0 -> 1. Or you could say the outdegree . same thing tbh.
/*
    This solution employs a topological sorting approach to solve the "Loud and Rich" problem efficiently. Let's break down the solution:

Understanding the Problem:
The goal is to find the quietest person among all people who are at least as wealthy as each person x.
We need to ensure that the quietest person among the richer individuals is assigned to each person x.
Explanation of the Approach:
The solution uses a directed graph where each person x has an edge to each person y if y is richer than x.
Topological sort is performed on this graph to ensure that the quietest person among the richer individuals is determined correctly.
Initially, all individuals are assigned themselves as the quietest person (ans[i] = i).
We start with the individuals who have no one richer than them (indegree is 0) and perform BFS topological sort.
During BFS traversal, for each person v, we update the quietest person (ans[u]) among the people who are richer than v.
If the current quietest person (ans[v]) is quieter than the quietest person among the richer individuals (ans[u]), we update ans[u] to be ans[v].
This process ensures that each person is assigned the quietest person among the richer individuals.
Code Explanation:
The code initializes vectors to represent the directed graph (adj), the indegree of each node (indegree), and the final answer (ans).
It constructs the directed graph based on the richer relationships provided in the input.
BFS topological sort is performed, starting with individuals who have no one richer than them (indegree[i] == 0).
During BFS traversal, the quietest person among the richer individuals is updated for each person.
The final answer ans is returned.
Complexity Analysis:
The time complexity of this solution is O(N + M), where N is the number of people and M is the number of richer relationships.
The space complexity is also O(N + M) due to the storage of the graph and other data structures.
*/
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) //topological sort
    {
        int n = quiet.size();
        vector<int> ans(n), adj[n], indegree(n,0);
        queue<int> q;
        int v;
        
        for(auto r: richer)
        {
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }
        for(int i=0; i<n; i++)
        {
            ans[i] = i;
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())   //BFS topo sort
        {
            v = q.front(), q.pop();
            
            for(auto u: adj[v])
            {
                if(quiet[ans[v]] < quiet[ans[u]])  //v is richer than u and b/c ans[v] can also be some other value than v which is more rich and is quietest and quieter than ans[u] then ans[u] will be ans[v]
                    ans[u] = ans[v];
                if(--indegree[u] == 0)
                    q.push(u);
            }
        }
        return ans;
    }
};
