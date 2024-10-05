#include <iostream>

using namespace std;

bool g(int a, int b) {
    if( a % 10 == 0 && b % 10 == 0 )
        return false;

    double r = (double)a / b;

    double p, q;

    int a_0 = a % 10;
    int a_1 = ( a / 10 ) % 10;

    int b_0 = b % 10;
    int b_1 = ( b / 10 ) % 10;

    if( a_0 == b_0 ) {
        p = a_1;
        q = b_1;
    }
    else if( a_0 == b_1 ) {
        p = a_1;
        q = b_0;
    }
    else if( a_1 == b_0 ) {
        p = a_0;
        q = b_1;
    }
    else if( a_1 == b_1 ) {
        p = a_0;
        q = b_0;
    }
    else    
        return false;

    return p / q == r;

}

int f(int n) {
    int a = 1;
    int b = 1;

    for(int i = 10; i < 100; i++)
        for(int j = i + 1; j < 100; j++)
            if( g(i, j) ) {
                a *= i;
                b *= j;
            }
    
    for( ; !( a & 1 ) && !( b & 1 ) ; ) {
        a /= 2;
        b /= 2;
    }

    for(int i = 3; i*i <= max(a, b); i += 2) {
        for( ; ( a % i == 0 ) && ( b % i == 0 ); ) {
            a /= i;
            b /= i;
        }
    }

    return b;
}

int main() {
    int n = 2;

    cout << f(n) << endl;

    return 0;
}
