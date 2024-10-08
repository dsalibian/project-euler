#include <iostream>
#include <string>

using namespace std;

bool pandigital(int n) {
    uint16_t t = 0;

    for( ; n > 0; ) {
        int m = n % 10;
        n /= 10;

        if( t & (1 << m)  )
            return false;

        t |= 1 << m;
    }

    return  !( t ^ 0b11'1111'1110 );
}

int g(int n) {
    int max = 0;

    for(int i = 100; ; i++) {
        string s = "";
        for(int j = 1; j <= n; j++)
            s += to_string( i * j );

        if( s.length() > 9 )
            return max;

        int m = stoi(s);
        if( pandigital(m) )
            max = std::max(max, m);

    }
}

int f() {
    int max = 0;

    for(int i = 2; i < 10; i++) 
        max = std::max(max, g(i));
    
    return max;
}

int main() {
    cout << f() << endl;

    return 0;
}
