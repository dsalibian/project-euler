#include <iostream>

using namespace std;

int f(int n) {
    int sum = 0;
    int a = 1;
    int b = 2; 

    for( ; b <= n; ) {
        if( b % 2 == 0 ) 
            sum += b;

        int t = b;
        b = a + b;
        a = t;
    }
    return sum;
}

int main() {
    int n = 4'000'000;

    cout << f(n) << endl;

    return 0;
}
