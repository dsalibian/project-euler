#include <iostream>
#include <cmath>

using namespace std;

struct result {
    bool p_1;
    bool m_1;
};

result g(uint64_t n) {
    uint64_t n_p1 = n + 1;
    uint64_t t0 = 4 * n * n - n_p1*n_p1;
    uint64_t t0_r = sqrt(t0);

    uint64_t n_m1 = n - 1;
    uint64_t t1 = 4 * n * n - n_m1*n_m1;
    uint64_t t1_r = sqrt(t1);

    return result {t0_r*t0_r == t0, t1_r*t1_r == t1};
}

int f(uint64_t n) {
    int s = 0;
    result r { g(5) };
    for(int i = 5; i <= 333'333'333; i += 2, r = g(i)) 
        if( r.p_1 || r.m_1 ) 
            s += 3 * i + ( r.p_1 ? 1 : -1 );
    
    return s;
}

int main() {
    uint64_t n = 1'000'000'000;
    
    cout << f(n) << endl;

    return 0;
}
