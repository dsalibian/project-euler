#include <iostream>

using namespace std;

uint64_t binomial(int n, int k) {
    if( k == 0 ) 
        return 1;
    return ( n * binomial(n - 1, k - 1) ) / k ;
}
 
uint64_t f(int n) {
    return binomial(n + n, n);
}

int main() {
    int n = 20;

    cout << f(n) << endl;

    return 0;
}
