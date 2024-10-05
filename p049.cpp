#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

vector<int> primes(int a, int b) {
    vector<int> arr;

    for(int i = a & 1 ? a : a + 1; i < b; i += 2)
        if( prime(i) )
            arr.push_back(i);
    
    return arr;
}

bool is_perm(int a, int b, int c) {    
    uint16_t t0 = 0;
    uint16_t t1 = 0;
    uint16_t t2 = 0;

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

    for( ; c > 0; ) {
        int m = c % 10;
        c /= 10;

        t2 |= 1 << m;
    }

    return  !( t0 ^ t1) & !( t0 ^ t2) & !( t1 ^ t2)  ;
}

string f(int n) {
    int count = 0;
    
    int u = pow(10, n);
    int l = pow(10, n -1);

    vector<int> arr = primes(l, u);

    for(int i = 0; i < arr.size(); i++) {
        int a = arr[i];
        for(int j = i + 1; j < arr.size(); j++) {
            int b = arr[j];

            int c = b + ( b - a );

            if( c > u || !prime(c) )
                continue;

            if( is_perm(a, b, c) ) 
                if( count > -1 )
                    return to_string(a) + to_string(b) + to_string(c);
                else    
                    count++;   
        }
    }
    
    return "0";
}

int main() {
    int n = 4;

    cout << f(n) << endl;

    return 0;
}
