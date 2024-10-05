#include <iostream>

using namespace std;

int g(int n) {
    int count = 0;

    for(int a = 1; a < n; a++) 
        for(int b = a; b < n - a; b++) 
            if( a*a + b*b == ( n - a - b )*( n - a - b ) )
                count++;

    return count;
}

int f(int n) {
    int max = 0;
    int maxi = 0;

    for(int i = 3; i <= n; i++) {
        int m = g(i);
        
        if( m > max ) {
            max = m;
            maxi = i;
        }
    }

    return maxi;
}

int main() {
    int n = 1'000;
    
    cout << f(n) << endl;

    return 0;
}
