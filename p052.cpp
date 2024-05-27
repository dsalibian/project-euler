#include <iostream>
#include <chrono>

using namespace std;

bool is_perm(int a, int b) {    
    int t0 = 0;
    int t1 = 0;

    for( ; a > 0; ) {
        int m = a % 10;
        a /= 10;

        t0 |= 1 << m;
    }

    for( ; b > 0; ) {
        int m = b % 10;
        b /= 10;

        t1 |= 1 << m;
    }

    return  !( t0 ^ t1) ;
}

int f() {
    for(int i = 1; ; i++) 
        if( is_perm(i, 2*i) && 
            is_perm(i, 2*i) && 
            is_perm(i, 4*i) && 
            is_perm(i, 5*i) && 
            is_perm(i, 6*i) )

            return i;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}