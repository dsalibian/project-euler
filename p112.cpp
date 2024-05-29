#include <iostream>
#include <chrono>

using namespace std;

bool increasing(int n) {
    for( ; n > 0; ) {
        int m = n % 10;
        n /=10;
        if( m < n % 10 )
            return false;
    }
    return true;
}

bool decreasing(int n) {
    for( ; n > 0; ) {
        int m = n % 10;
        n /=  10;
        if( m > ( n % 10 ) && n != 0 )
            return false;
    }
    return true;
}

bool bouncy(int n) {
    return !increasing(n) && !decreasing(n);
}

int f(double r_max) {
    double r = 0;
    int c = 0;
    for(int i = 100; ; i++) {
        if( bouncy(i) )
            c++;

        r = (double)c/i;
        if( r > r_max )
            return --i;
    }
}

int main() {
    double r = 0.99;

    auto start = chrono::steady_clock::now();
    int result = f(r);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}