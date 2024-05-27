#include <iostream>
#include <chrono>

using namespace std;

int binomial(int n, int k) {
    if( k == 0 ) 
        return 1;
    return ( n * binomial(n - 1, k - 1) ) / k ;
}

int f() {
    int c = 0;
    for(int i = 1; i <= 100; i++) 
        for(int j = 0; j <= i; j++) 
            if( binomial(i, j) > 1'000'000 ) {
                c += i + 1 - 2 * j;
                break;
            }

    return c;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}