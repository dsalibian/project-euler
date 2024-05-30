#include <iostream>
#include <chrono>
#include <cmath>
#include <unordered_set>

using namespace std;
typedef unsigned long long ull;

ull reverse(ull n) {
    ull m = 0;

    ull k = pow(10, (int)(log10(n)) );
    for( ; n > 0; ) {
        m += k * (n % 10);
        k /= 10;
        n /= 10;
    }
    
    return m;
}

bool prime(ull n) {
    if( !(n & 1) )
        return false;

    ull u = sqrt(n);
    for(ull i = 3; i <= u; i += 2) 
        if( n % i == 0 ) 
            return false;
    
    return true;
}

int next_prime(int n) {
    for(int i = n & 1 ? n + 2 : n + 1; ; i += 2)
        if( prime(i) )
            return i;
}

ull f(int n) {
    ull sum = 0;

    unordered_set<ull> set;

    int c = 0;
    for(ull i = 2; ; i = next_prime(i)) {
        ull t = i*i;
        ull m = reverse(t);

        if( m == t )
            continue;

        ull k = sqrt(m);
        if( k*k == m && prime(k) && !set.count(t) && !set.count(m) ) {
            set.insert( {t, m } );
            sum += t + m; 
            c += 2;
        }

        if( c == n )
            return sum;
    }
}

int main() {
    int n = 50;

    auto start = chrono::steady_clock::now();
    ull result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}