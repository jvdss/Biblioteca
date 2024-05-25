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
const int MAX  = 2e5+4;

int grid[1001][1001];
int dp[1001][1001];

void solve(){
    int n, m; cin >> n >> m;

    FOR(i, n){
        FOR(j, m){
            cin >> grid[i][j];

            dp[i][j] = 1;

            if(j > 0 and grid[i][j-1] == grid[i][j]){
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    int ans = 0;

    FOR(i, n){
        FOR(j, m){
            int x = grid[i][j];
            int cur = dp[i][j];
            // int add =  cur;
            ans += cur;
            int ii = i-1;

            while(ii >= 0 and grid[ii][j] == x){
                ans++;
                cur = min(cur, dp[ii][j]);
                ans += cur - 1;
                // add += cur ;
                ii--;
            }
            // cout << add << " \n"[j==m-1];
            // cout << ans << endl;
        }
    }

    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}