#include <iostream>
#include <chrono>
#include <cmath>
#include <set>

using namespace std;

int len(int n) {
    return log10(n) + 1;
}

bool pandigital(int a, int b, int c) {
    uint16_t t = 0;

    for( ; a > 0; ) {
        int n = a % 10;
        a /= 10;

        if( t & (1 << n)  )
            return false;

        t |= 1 << n;
    }

    for( ; b > 0; ) {
        int n = b % 10;
        b /= 10;
        
        if( t & (1 << n) )
            return false;

        t |= 1 << n;
    }

    for( ; c > 0; ) {
        int n = c % 10;
        c /= 10;

        if( t & (1 << n) )
            return false;

        t |= 1 << n;
    }

    return  !( t ^ 0b11'1111'1110 );
}

int f() {
    int sum = 0;

    set<int> u;

    for(int i = 1; i < 1e2; i++) {
        for(int j = i + 1; ; j++) {
            int k = i * j;

            int l = len(i) + len(j) + len(k);

            if( l > 9 )
                break;
            
            if( l != 9 )
                continue;

            if( pandigital(i, j, k) ) {
                int s = u.size();
                u.insert(k);
                
                if( u.size() != s )
                    sum += k;
            }
            
        }
    }

    return sum;
}

int main() {
    auto start = chrono::steady_clock::now();
    int result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
