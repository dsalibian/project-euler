#include <iostream>
#include <chrono>

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

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
