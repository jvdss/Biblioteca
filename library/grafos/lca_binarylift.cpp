// LCA com binary lifting
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh raiz up[a][0] = a
// se a eh ancestral de b, lca(a, b) = a
// LOG = ceil(log(MAX))
//
// Complexidades:
// build - O(n log(n))
// lca - O(log(n))

vector<vector<int>> g; // [N]
vector<vector<int>> up; // [N][LOG]
vector<int> depth; // [N]
// int LOG = 0; while( 1 << LOG <=n ) LOG++;

void dfs(int u, int p = 0){
    up[u][0] = p;
    for(int j = 1; j < LOG; ++j)
        up[u][j] = up[ up[u][j-1] ][j-1];
    

    for(auto v : g[u]) if(v!=p){
        depth[v] = depth[u] + 1;
        dfs(v,u);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);

    // encontra o kth ancestral de a t.q. depth[a] == depth[b]
    int k = depth[a] - depth[b];
    for(int j = 0; j < LOG; ++j) if( k & ( 1 << j ) )
        a = up[a][j];
        
    if(a==b) return a;

    for(int j = LOG-1; j>=0; --j )
        if( up[a][j] != up[b][j])
            a = up[a][j], b = up[b][j];
        
    return up[a][0];
}
