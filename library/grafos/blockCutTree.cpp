// Block-Cut Tree (bruno monteiro)
// 
// 2-Vertex connected components
// - Dados dois vertices numa componente biconexa 
// Há pelo menos 2 caminhos disjuntos em vértices entre eles (passam por vértices distintos)
// 
// - Dados duas arestas numa componente biconexa 
// Há um ciclo simples que passa por essas arestas
// 
// --------------------------------------------------------------
// 
// Cria a block-cut tree, uma arvore com os blocos
// e os pontos de articulacao
// Blocos sao as componentes 2-vertice-conexos maximais
// Uma 2-coloracao da arvore eh tal que uma cor sao
// os componentes, e a outra cor sao os pontos de articulacao
//
// isAP[i] responde o numero de novas componentes conexas
// criadas apos a remocao de i do grafo g
// Se isAP[i] >= 1, i eh ponto de articulacao
// 
// Para todo i < blocks.size()
// blocks[i] eh uma componente 2-vertce-conexa maximal
// blockEdges[i] sao as arestas do bloco i
//
// tree é a arvore block-cut-tree
// tree[i] eh um vertice da arvore que corresponde ao bloco i
// 
// comp[i] responde a qual vertice da arvore vertice i pertence
//
// Arvore tem no maximo 2n vertices
// Funciona para grafo nao conexo
// 
// O(n+m) 0-index!!!
struct block_cut_tree{
    vector< vector<int> > g, blocks, tree; // 2-vertex-connected-components
    vector< vector< pair< int, int >>> blockEdges;
    vector<int> low, tin, comp, isArt;
    stack< pair< int, int> > ste; // stack for edges
    stack<int> stv; // stack for vertices
    ll timer;

    block_cut_tree( vector<vector<int>> g_ ) : g( g_ ), timer(0) { 
        int n = (int) g.size();
        tin = vector<int>( n, -1);
        low = comp = isArt = vector<int>(n, 0);
        build(n);
    }

    void build(int n){
        
        // find Articulation Points
        for(int i = 0; i < n; ++i) if( tin[i] == -1)
            dfs(i);

        // set component id for ArtPs
        tree.assign( blocks.size(), vector<int>());
        for(int i = 0; i < n; ++i) if( isArt[i] )
            comp[i] = tree.size(), tree.pb( vector<int>() );

        // set component id for non-ArtPs and construct tree
        for(int u = 0; u < (int) blocks.size(); ++u){
            for( auto v : blocks[u] ){
                if( !isArt[v] )
                    comp[v] = u;
                else 
                    tree[u].pb( comp[v] ), tree[ comp[v] ].pb(u);
            }
        }  
    }

    void dfs(int u, int p = -1){
        tin[u] = low[u] = timer++;

        stv.push( u );

        // add parent edges
        if( p != -1 ) ste.push({ u, p });
        
        // add only back-edges to stack i.e tin[v] != -1
        for(auto v : g[u]) if ( v != p and tin[v] != -1 )
            ste.push({u, v });
            
        for(auto v : g[u] ) if( v != p ){
            if( tin[v] != -1 ){ // visited 
                low[u] = min( low[u], tin[v]);
                continue;
            }

            dfs(v,u);
            low[u] = min(low[u], low[v]);

            // u isArt
            if( low[v] >= tin[u] ){
                ++isArt[u];

                blocks.pb( vector<int>(1, u) );
                while( blocks.back().back() != v)
                    blocks.back().pb( stv.top() ), stv.pop();

                
                blockEdges.pb( vector<pair<int,int>>(1, ste.top()) ); ste.pop();
                while(blockEdges.back().back() != pair< int, int >(v, u))
                    blockEdges.back().pb( ste.top() ), ste.pop();
            }
        }
        // root corner case
        if( p == -1 and isArt[u]) --isArt[u];
    }
};