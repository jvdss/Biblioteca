
// 31ballons O( n*log^2(n) )
bitset<MAX> is_prime;
void build(){
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i*i < MAX; ++i){
        if( is_prime[i] ){
            for(int j = i*i; j < MAX; j+=i) is_prime[j] = false;
        }
    }
}