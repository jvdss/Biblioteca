#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define pb push_back
#define ss second
#define ff first
// #define endl '\n'
#define int long long
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int INF = 0x3f3f3f3f;
const int MAX  = 202500;
const int T = 450;
 
int a[MAX], blockIds[MAX];
int b[T];

void solve(){
    int n, q; cin >> n >> q;

    FOR(i,T) b[i] = INF;
    FOR(i,MAX) a[i] = INF;

    FOR(i,n){
        int x; cin >> x;
        a[i] = x;
        blockIds[i] = i/T;
        b[blockIds[i]] = min(a[i],b[blockIds[i]]);
    }

    auto update = [&](int i, int x){
        --i;
        int id = blockIds[i];
        a[i] = x;
        b[id] = INF;
        for(int j = id*T, end = (id+1)*T - 1; j<= end; ++j) 
            b[id] = min(b[id], a[j]);
    };

    auto query = [&](int l, int r){
        --l; --r;
        int ret = INF;
        int cl = blockIds[l], cr = blockIds[r];
        if( cl == cr ){
            for(int i = l; i <=r; ++i) ret = min(ret,a[i]);
        }else{
            for(int i = l, end = (cl+1)*T - 1; i<= end; ++i) ret = min(ret,a[i]);
            for(int i = cl+1; i < cr; ++i) ret = min(ret,b[i]);
            for(int i = cr*T; i<= r; ++i) ret = min(ret,a[i]);
        }

        return ret;
    };

    while(q--){
        int op, x, y; cin >> op >> x >> y;

        if(op==2){
            cout << query(x,y) << endl;
        }else{
            update(x,y);
        }
    }

}
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int test = 1;
    // cin >> test;
    while(test--){
        solve();
    }
    return 0;
}