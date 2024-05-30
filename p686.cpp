#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int d(int n, int k) {
    double m = log10(2);
    return exp10(n*m - 1 - (int)(n*m) + k);
}

int f(int L, int n) {
    int m = log10(L) + 1;
    int c = 0;
    for(int i = 1; ; i++) {
        if( d(i, m) == L )
            c++;

        if( c == n )
            return i;
    }
}

int main() {
    double L = 123;
    double n = 678'910;

    auto start = chrono::steady_clock::now();
    int result = f(L, n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}