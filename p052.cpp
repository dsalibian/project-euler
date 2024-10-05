#include <iostream>

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
    for(int i = 1;; i++) {
        for(int j = 1; j < 7; ++j)
            if( !is_perm(i, j * i) ) 
                goto cont;

        return i;
        cont:;
    }

}

int main() {
    cout << f() << endl;

    return 0;
}
