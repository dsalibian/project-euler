#include <iostream>
#include <cmath>

using namespace std;

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}


bool g(int n) {    
    int t = 0;
    for(int i = 0; t < n; i++, t = 2 * i * i) 
        if( prime( n - t ) )
            return true;
    
    return false;
}

int f() {
    for(int i = 3; ; i += 2) 
        if( !g(i) )
            return i;
}

int main() {
    cout << f() << endl;

    return 0;
}
