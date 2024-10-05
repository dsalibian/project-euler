#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2) 
        if( n % i == 0 ) 
            return false;
    
    return true;
}

int next_prime(int n) {
    for(int i = n & 1 ? n + 2 : n + 1; ; i += 2)
        if( prime(i) )
            return i;
}

int phi(int n) {
    double p = 1;

    int u = sqrt(n);
    for(int k = 2; k <= u; k = next_prime(k)) 
        if( !( n % k ) )
            p *= 1 - 1.0 / k;

    return n * p;
}

int f(int n) {
    double max_r = 0;
    int max_p = 0;
    
    uint64_t p = 1;
    for(int k = 2; p*k < n; k = next_prime(k)) {
        p *= k;

        double r = (double)p/phi(p);
        if( r > max_r ) {
            max_r = r;
            max_p = p;
        }
    }
    return max_p;
}

int main() {    
    int n = 1'000'000;
    
    cout << f(n) << endl;

    return 0;
}
