#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

bool g(int n, int p) {
    int n_copy = n;
    int sum = 0;

    for( ; n != 0; ) {
        int m = n % 10;
        sum += pow(m, p);
        n /= 10;
    }

    return sum == n_copy;
}

int f(int n) {
    int sum = 0;
    
    int u = pow(9, n) * n;
    for(int i = 2; i <= u; i++) {
        if( g(i, n) ) 
            sum += i;
        
    }
    
    return sum;
}

int main() {
    int n = 5;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
