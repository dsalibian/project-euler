#include <iostream>

using namespace std;

int length(uint64_t n) {
    int count = 1;

    for( ; n != 1 ; count++) {
        if( n % 2 == 0) 
            n /= 2;
        else 
            n = 3 * n + 1;
    }

    return count;
}

int f(int n){
    int maxlen = 0;
    int maxn = 0;

    for(int i = 1; i < n; i++) {
        int len = length(i);
        if( len > maxlen ) {
            maxlen = len;
            maxn = i;
        }
    }
    
    return maxn;
}

int main() {
    int n = 1'000'000;
    
    cout << f(n) << endl;

    return 0;
}
