// Struct de ponto
typedef long long T;
struct point{
    T x, y;
    int id;
    point(T x=0, T y=0): x(x), y(y){}

    point operator+(const point &o) const{ return {x + o.x, y + o.y}; } // a + b
    point operator-(const point &o) const{ return {x - o.x, y - o.y}; } // a - b
    point operator*(T t) const{ return {x * t, y * t}; } // a * t
    point operator/(T t) const{ return {x / t, y / t}; } // a / t
    T operator*(const point &o) const{ return x * o.x + y * o.y; } // Escalar  (a * b)
    T operator^(const point &o) const{ return x * o.y - y * o.x; } // Vetorial (a ^ b)
};

// Mirror ponint p around segment m1m2
point mirror(point m1, point m2, point p){
    point seg = m2-m1;
    ld t0 = ((p-m1)*seg) / (seg*seg);
    point ort = m1 + seg*t0;
    point pm = ort-(p-ort);
    return pm;
}


// Angular sort
int ret[2][2] = {{3, 2},{4, 1}}; 
inline int quad(point p) {
    return ret[p.x >= 0][p.y >= 0];
}

bool comp(point a, point b) { // ccw
    int qa = quad(a), qb = quad(b);
    return (qa == qb ? (a ^ b) > 0 : qa < qb);
}

vector<point> v;
sort(v.begin(), v.end(), comp);
