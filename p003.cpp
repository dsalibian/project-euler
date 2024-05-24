#include <iostream>
#include <chrono>

using namespace std;

uint64_t f(uint64_t n) {
    for(uint64_t i = 3; i < n; i += 2)
        for( ; n % i == 0; )
            n /= i;

    return n;
}

int main() {
    uint64_t n = 600'851'475'143ULL;

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}
