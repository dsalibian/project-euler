#include <iostream>
#include <cmath>

using namespace std;

bool palindrome(int n) {
    int reversed = 0;
    int copy = n;

    for( ; copy != 0; ) {
        reversed *= 10;
        reversed += ( copy % 10 );
        copy /= 10;
    }

    return reversed == n;
}

int f(int n) {
    int u = pow(10, n);
    int l = pow(10, n - 1);
    int max = -1;

    for(int i = l; i < u; i++) {
       for(int j = i; j < u; j++) {
            int product = i * j;
            if( palindrome(product) && ( product > max ) ) 
                max = product;
       }
    } 

    return max;
}

int main() {
    int n = 3;
    
    cout << f(n) << endl;

    return 0;
}
