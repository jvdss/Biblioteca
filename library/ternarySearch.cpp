// approx O(log n)

// Doubles
double ternarySearch(double l, double r){
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}

// Integers
// Ternary search will have to stop when (r-l) < 3   
// therefore run it while r - l >= 3  --> r >= 3 + l -->  ( r > l + 2 )
// because in that case we can no longer select m1, m2 to be different from each other as well as from l and r 
// this can cause an infinite loop!!

int l = 0, r = n-1;
while( r > l + 2 ){
    int m1 = l + (r-l)/3;
    int m2 = r - (r-l)/3;
    if( f(m1) < f(m2)  ) r = m2 ;
    else l = m1 ;
}

int aux = f(l++);
while( l <= r) cost = max(cost, f(l++) );

// the remaining pool of candidate points (l, l+1,...,r) 
// needs to be checked to find the point which produces the maximum value