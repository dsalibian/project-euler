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

int f(int n) {
    int count = 1;
    for(int i = 3; ; i += 2) {
        if( prime(i) ) 
            count++;
            
        if( count == n ) 
            return i;

    }
}

int main() {
    int n = 10'001;

    cout << f(n) << endl;

    return 0;
}
