vector<int> topo(int V, vector<int> adj[]){
   int indeg[V] = {0};

   for(int i = 0; i < V; i++){
      for(auto n : adj[i]){
         indeg[n]++;
      }
   }

   queue<int> q;
   for(int i = 0; i < V; i++){
      if(indeg[i] == 0){
         q.push(i);
      }
   }

   int count = 0;

   while(!q.empty()){
      int node = q.front(); q.pop();
      count ++;

      for(n : adj[node]){
         indeg[n]--;
         if(indeg[n] == 0){
            q.push(n);
         }
      }
   }
   
   return count == V ? false : true;
}
