#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n) {
    int p = 1;

    for(int i = 2; i <= n; i++)
        p *= i;
    
    return p;
}

bool g(int n) {
    int n_copy = n;
    int sum = 0;

    for( ; n > 0; ) {
        sum += factorial( n % 10 );
        n /= 10;
    }

    return sum == n_copy;
}

int len(int n) {
    return log10(n) + 1;
}

int f() {
    int sum = 0;
    
    int u = factorial(9);
    for(int i = 10; u * len(i) > i; i++) 
        if( g(i) )
            sum += i;
    
    return sum;
}

int main() {
    cout << f() << endl;

    return 0;
}
