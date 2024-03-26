// just another detect a cycle type problem.
func dfs(src int, adj [][] int, vis [] int) bool{
    vis[src] = 2;

    for _, value := range adj[src]{
        if (vis[value] == 0){
           if (dfs(value, adj, vis)){
                return true;
           }
        } else if (vis[value] == 2){
            return true;
        }
    }

    vis[src] = 1;
    return false;
}

func canFinish(n int, pr [][]int) bool {
    adj := make([][] int, n);

    for i := 0; i < len(pr); i++ {
        adj[pr[i][1]] = append(adj[pr[i][1]], pr[i][0])
    }
       
    vis := make([] int, n);

    for i := 0; i < n; i++{
        vis[i] = 0;
    }

    for i := 0; i < n; i++{
        if (vis[i] == 0 && dfs(i, adj, vis)){
            return false;
        }
    }

    return true;
}
