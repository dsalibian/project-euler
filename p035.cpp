#include <iostream>
#include <chrono>
#include <cmath>
#include <string>

using namespace std;

bool prime(int n) {
    if( n == 2 )
        return true;
    if( !( n & 1 ) )
        return false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

bool circular(int n) {
    int u = log10(n) + 1;
    for(int i = 0; i < u; i++) {
        if( !prime(n) )
            return false;

        n = ( n + ( n % 10 ) * pow(10, u) ) / 10;
    }

    return true;
}

int f(int n) {
    int count = circular(2) ? 1 : 0;

    for(int i = 3; i < n; i += 2)
        if( circular(i) )
            count++;
    
    return count;
}

int main() {
    int n = 1'000'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}