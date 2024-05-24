#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int numofdivisors(int n) {
    int count = 2;

    int u = sqrt(n);
    for(int i = 1; i <= u; i++) {
        if( n % i == 0 ) {
            if( i == u ) 
                count++;
            else 
                count += 2;
        }
    }

    return count;
}

int f(int n) {
    for(int i = 1, t = 1; ; i++, t += i) 
        if( numofdivisors(t) > n ) 
            return t;
    
}

int main() {
    int n = 500;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}