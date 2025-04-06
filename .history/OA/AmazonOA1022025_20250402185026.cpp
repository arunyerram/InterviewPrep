

// ......................DFS......................
dfs(int i){
    vis[i] = true;

    for(auto it:adj[i]){
        if(!vis[it]) 
            dfs(it);
    }
    print(i);

    return;
}