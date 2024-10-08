#include <iostream>
#include <cmath>

using namespace std;

uint64_t hex(uint64_t n){
    return 2 * n * n - n;
}

bool is_pent(uint64_t n) {
    n = 24 * n + 1;
    uint64_t m = sqrtl(n);
    return m * m == n && m % 6 == 5;
}

bool is_tri(uint64_t n) {
    n = 8 * n + 1;
    uint64_t m = sqrtl(n);
    return m * m == n;
}

uint64_t f() {
    for(int i = 144; ; i++) {
        uint64_t hn = hex(i);
        if( is_tri(hn) && is_pent(hn) ) 
            return hn;   
    }
}

int main() {
    cout << f() << endl;

    return 0;
}
