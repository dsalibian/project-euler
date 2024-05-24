#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int f(int n) {
    return abs( ( n * ( n * n - 1 ) * ( 3 * n + 2 ) ) / 12 );
}

int main() {
    int n = 100;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}


