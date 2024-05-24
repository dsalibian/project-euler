#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

bool prime(int n) {
    if( n < 2 )
        return false;
    if( n == 2 )
        return true;
    if( n % 2 == 0 )
        return false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

int f(int n) {
    int max = 0;
    int maxp = 0;

    for(int i = -n + 1; i < n; i++) {
        for(int j = -n; j <= n; j++) {
    
            int m = 0;
            for(int k = 0; ; k++) {
                if( prime( k*k + i*k + j ) )
                    m++;
                else 
                    break;
            }

            if( m > max ) {
                max = m;
                maxp = i * j;
            }
        }
    }
    return maxp;
}

int main() {
    int n = 1'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}