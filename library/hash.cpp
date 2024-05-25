const long long mod1 = 1000015553, mod2 = 1000028537;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Random number generator
static long long base1 = uniform_int_distribution<int>(356, mod1 - 1)(rng); // In case TL, use const
static long long base2 = uniform_int_distribution<int>(356, mod2 - 1)(rng);
// Remember (alfabet < base < mod)

struct hash_s{
    long long n;
    string s;
    vector<long long> hsh1, pwr1, hsh2, pwr2;

    hash_s() : n(0) {}
    hash_s(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n), hsh2(n), pwr2(n){
        pwr1[0] = pwr2[0] = 1;
        for (int i = 1; i < n; i++){
            pwr1[i] = (base1 * pwr1[i - 1]) % mod1;
            pwr2[i] = (base2 * pwr2[i - 1]) % mod2;
        }
        hsh1[0] = hsh2[0] = s[0];
        for (int i = 1; i < n; i++){
            hsh1[i] = (hsh1[i - 1] * base1 + (long long)(s[i]))%mod1;
            hsh2[i] = (hsh2[i - 1] * base2 + (long long)(s[i]))%mod2;
        }
    }

    long long hash(int i, int j){ // hash no intervalo [i, j]
        if (i == 0) return (hsh1[j] << 30)^(hsh2[j]);;
        long long ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
        long long ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
        return (ret1 << 30)^(ret2);
    }
};

/*
seja s = "abcdef"
          012345
as posições do vetor hsh vao ser as seguintes
0 | a*base^0
1 | a*base^1 + b*base^0
2 | a*base^2 + b*base^1 + c*base^0
3 | a*base^3 + b*base^2 + c*base^1 + d*base^0
4 | a*base^4 + b*base^3 + c*base^2 + d*base^1 + e*base^0
5 | a*base^5 + b*base^4 + c*base^3 + d*base^2 + e*base^1 + f*base^0

basicamente cada i = somatorio [ j = 0 até i] de s[j]*base^( i -j )

Como conseguir o intervalo [l,r]?
sabendo que hsh[i] guarda a soma acumulade de [0,i]
com hsh[l-1] e hsh[r] temos somas acumuladas
hsh[l-1] deve ser multiplicado por base ^ (j-i+1)
j-i+1 = quantidade de vezes que os valores foram multiplicados por base até r
j - i + 1 = r - l + 1
*/