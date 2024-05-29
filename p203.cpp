#include <iostream>
#include <chrono>
#include <cmath>
#include <set>

using namespace std;

uint64_t binomial(int n, int k) {
    if( k == 0 ) 
        return 1;
    return ( n * binomial(n - 1, k - 1) ) / k ;
}

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2) 
        if( n % i == 0 ) 
            return false;
    
    return true;
}

bool squarefree(uint64_t n) {
    if( !(n & 1) )
        n /= 2;

    if( !(n & 1))
        return false;

    for(uint64_t i = 3; i <= sqrt(n); i += 2) {
        if( !(n % i) )
            n /= i;
        
        if ( !(n % i) )
            return false;
    }

    return true;
}

uint64_t f(int n) {
    set<uint64_t> set;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j <= i/2; j++) {
            uint64_t m = binomial(i, j);
            if( squarefree(m) ) 
                set.insert(m);
        }

    uint64_t sum = 0;
    for( uint64_t n: set) 
        sum += n;

    return sum;
}

int main() {
    int n = 51;

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}