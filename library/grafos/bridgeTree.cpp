// BridgeTree
// 2-edge connected component
// For each pair of vertices {A, B} inside the same connected component, 
// there are at least 2 distinct paths in edges from A to B (may repeat vertices).

// g: u -> { v, edgeId }
vector<pair<int,int>>> g(MAX);
vector<int> gc[MAX];
int timer;
int tin[MAX], low[MAX], comp[MAX];
bool isBridge[MAX];

void dfs(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    for(auto [v, id] : g[u]) if (v != p) {
        if (tin[v])
            low[u] = min(low[u], tin[v]); 
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                isBridge[id] = 1;
        }   
    }
}

void dfs2(int u, int c, int p = -1) {
    comp[u] = c;
    for(auto [v, id] : g[u]) if (v != p) {
        if (isBridge[id]) continue;
        if ( comp[v] == -1 ) dfs2(v, c, u);
    }
}

int bridgeTree(int n) {
    for(int i = 0 ; i < n; ++i) comp[i] = -1, tin[i] = 0;
    timer = 1;
    
    // find bridges
    for(int i = 0 ; i < n; ++i) if (!tin[i])
        dfs(i);

    // find components
    int c = 0;
    for(int i = 0 ; i < n; ++i) if (comp[i] == -1) 
        dfs2(i, c++);

    // condensate into a TREE (or TREES if disconnected)
    for(int u = 0 ; u < n; ++u) {
        for(auto [v, id] : g[u]) {
            if (comp[u] != comp[v]) {
                gc[comp[u]].pb(comp[v]);
            }
        }
    }

    return c;
}