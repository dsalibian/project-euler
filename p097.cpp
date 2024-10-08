#include <iostream>
#include <cmath>

using namespace std;

uint64_t f(int n) {
    uint64_t mod = pow(10, n);
    
    uint64_t p = 28'433;
    for(int i = 0; i < 7'830'457; i++) {
        p *= 2;
        p %= mod;
    }

    return ++p;
}

int main() {
    int n = 10;

    cout << f(n) << endl;

    return 0;
}
