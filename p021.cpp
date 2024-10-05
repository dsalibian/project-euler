#include <iostream>
#include <cmath>

using namespace std;

int d(int n) {
    int sum = 1;

    int u = sqrt(n);
    for(int i = 2; i <= u; i++) {
        if( n % i == 0 ) {
            if( n/i == i ) 
                sum += i;
            else 
                sum += i + n/i;
        }
    }

    return sum;
}

int f(int n) {
    int sum = 0;

    for(int a = 0; a < n; a++) {
        int b = d(a);
        if( d(b) == a && a != b )
            sum += a;

    }
    return sum;
}

int main() {
    int n = 10'000;
    
    cout << f(n) << endl;

    return 0;
}
