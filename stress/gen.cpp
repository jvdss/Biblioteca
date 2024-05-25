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

ll randl(ll a, ll b){
	return rand()%(b-a+1) + a;
}

int rand(int a, int b){
	return rand()%(b-a+1) + a;
}


int32_t main(int argc, char** argv){
	ios::sync_with_stdio(false); cin.tie(0);
	srand(atoi(argv[1]));

    cout << 1 << endl;
    int n = rand(1,500);
    int m = rand(1,500);
    cout << n << " " << m << endl;
    FOR(i,n) FOR(j,m){
    	cout << rand(1,2) << " \n"[j==m-1];
    }
    
	exit(0);
}
