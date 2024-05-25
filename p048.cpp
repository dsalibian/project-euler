#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

uint64_t pow(int a, int b, int p) {
    uint64_t t = 1;
    uint64_t m = pow(10, p);

    for(int i = 0; i < b; i++) {
        t *= a;
        t %= m;
    }

    return t;
}

uint64_t f(int n, int p) {
    uint64_t sum = 0;
    uint64_t m = pow(10, p);

    for(int i = 1; i < n; i++) {
        sum += pow(i, i, p);
        sum %= m;
    }

    return sum;
}

int main() {
    int n = 1'000;
    int p = 10;

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n, p);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}