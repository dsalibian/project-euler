#include <iostream>
#include <cmath>

using namespace std;

int d(int n, int k) {
    double m = log10(2);
    return exp10(n*m - 1 - (int)(n*m) + k);
}

int f(int L, int n) {
    int m = log10(L) + 1;
    int c = 0;
    for(int i = 1; ; i++) {
        if( d(i, m) == L )
            c++;

        if( c == n )
            return i;
    }
}

int main() {
    int L = 123;
    int n = 678'910;

    cout << f(L, n) << endl;

    return 0;
}
