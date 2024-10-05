#include <iostream>
#include <cmath>

using namespace std;

int pent(int n){
    return n * ( 3 * n - 1 ) / 2;
}

int is_pent(int n) {
    n = 24 * n + 1;
    int m = sqrt(n);
    return m*m == n && m % 6 == 5;
}

int f() {
    int min = INT32_MAX;

    for(int i = 1; i < 10'000; i++) {
        int pa = pent(i);
        for(int j = i + 1; j < 10'000; j++) {
            int pb = pent(j);

            int a = pa + pb;
            int b = pb - pa;

            if(b > min)
                break;

            if( is_pent(a) && is_pent(b) )
                min = std::min(min, b);
        }
    }

    return min;
}

int main() {
    cout << f() << endl;

    return 0;
}
