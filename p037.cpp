#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n) {
    if( n < 2 )
        return false;
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

bool right(int n) {
    n /= 10;
    for( ; n > 0; ) {
        if( !prime(n) )
            return false;
        n /= 10;
    }
    return true;
}

bool left(int n) {
    int l = log10(n);

    int k = pow(10, l--);
    n -= k * ( n / k );

    for( ; n > 0; ) {
        if( !prime(n) )
            return false;

        k = pow(10, l--);
        n -= k * ( n / k );
    }

    return true;
}

int f() {
    int sum = 0;

    for(int i = 11, j = 0; j < 11; i += 2) 
        if( prime(i) && right(i) && left(i) ) {
            j++;
            sum += i;
        }
    
    return sum;
}

int main() {
    cout << f() << endl;

    return 0;
}
