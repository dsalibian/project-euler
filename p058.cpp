#include <iostream>
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

int f(double r) {
    int c = 0;
    int a = 0;
    int k = 1;
    int k_p = 0;

    for(int i = 1; ; i += a, c++, k++) {

        if( k > 10 && (double)k_p/(k) < r )
            return ++a;

        if( prime(i) )
            k_p++;

        if( c % 4 == 0 ){
            c = 0;
            a += 2;
        }

    }
}

int main() {
    double n = 0.1;
    
    cout << f(n) << endl;

    return 0;
}
