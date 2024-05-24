#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

uint64_t f(int n) {
    uint64_t sum = 2;
    for(int i = 3; i < n; i += 2)
        if( prime(i) ) 
            sum += i;
    return sum;
}

int main() {
    int n = 2'000'000;

    auto start = chrono::steady_clock::now();
    uint64_t result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}