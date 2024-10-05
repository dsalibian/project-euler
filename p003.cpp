#include <iostream>

using namespace std;

uint64_t f(uint64_t n) {
    for(uint64_t i = 3; i < n; i += 2)
        for( ; n % i == 0; )
            n /= i;

    return n;
}

int main() {
    uint64_t n = 600'851'475'143ULL;

    cout << f(n) << endl;

    return 0;
}
