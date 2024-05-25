#include <bits/stdc++.h>
using namespace std;

#define FOR(i_ , e_ )  for(int i_ = (int) 0 ; i_ <  (int) e_ ; ++i_ )
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
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
int dp2[1001][1001];

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

    FOR(j, m){

        stack<pii> stk;
        int h = 1;
        FOR(i, n){
            if(i == 0){
                dp2[i][j] = dp[i][j];
                stk.push({dp[i][j], i});
            }
            else{
                if(grid[i][j] == grid[i-1][j]){
                    h++;
                    if(dp[i][j] > dp[i-1][j]) {dp2[i][j] = dp[i][j] + dp2[i-1][j]; stk.push({dp[i][j], i});}
                    else{

                        while(stk.size() and stk.top().ff >= dp[i][j]) stk.pop();

                        if(stk.empty())dp2[i][j] = dp[i][j] * h;
                        else{
                            auto [lar, id] = stk.top();
                            dp2[i][j] = (i - id) * dp[i][j] + dp2[id][j];
                        }

                        stk.push({dp[i][j], i});
                    }
                } else{
                    dp2[i][j] = dp[i][j];
                    // stk.clear();
                    while(stk.size()) stk.pop();
                    stk.push({dp[i][j], i});
                    h = 1;
                }
            }

        }
    }

    int ans = 0;

    FOR(i, n){
        FOR(j, m){
            
            ans += dp2[i][j];
            // cout << dp2[i][j] << " \n"[j==m-1];
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