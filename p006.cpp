#include <iostream>

using namespace std;

int f(int n) {
    return abs( ( n * ( n * n - 1 ) * ( 3 * n + 2 ) ) / 12 );
}

int main() {
    int n = 100;

    cout << f(n) << endl;

    return 0;
}
