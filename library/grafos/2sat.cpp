// 2-SAT
//
// O(|V|+|E|) = O(#variaveis + #restricoes)

vi g[MAX][2];
int comp[MAX];
bool vis[MAX][2];
int qtdNode;
vi posOrdem;

void DFS(int u, int ind){
    
    vis[u][ind] = 1;
    
    for(auto v : g[u][ind]){

        if( vis[v][ind] ) continue;

        if( ind == 1 )
            comp[v] = comp[u];

        DFS(v,ind);

    }
    if( ind == 0 )
        posOrdem.push_back(u);
}


void kosaraju(){
    FOR(i,qtdNode) vis[i][0] = vis[i][1] = 0;

    FOR(i,qtdNode) if(!vis[i][0]) DFS(i, 0);

    int c = 0;
    while( posOrdem.size()){

        auto at = posOrdem.back(); posOrdem.pop_back();

        if(vis[at][1]) continue;

        comp[at] = ++c; 
        DFS(at, 1);
    }
}

void addEdge(int x, int y){
    g[x][0].pb(y);
    g[y][1].pb(x);
}

bool isPossible = true;    
string ans(qtdNode,'+');

for(int i = 0; i < qtdNode; i+=2){
    if(comp[i]==comp[i+1])
        isPossible = false;
    if(comp[i] < comp[i+1])
        ans[ i / 2 ] = '-';
}
