#include <iostream>

using namespace std;

int f(int n) {
    int sum = 0;
    int c = 0;
    int a = 0;

    for(int i = 1; i <= n*n; sum += i, i += a, c++) {
        if( c % 4 == 0 ){
            c = 0;
            a += 2;
        }
    }
    return sum;
}

int main() {
    int n = 1'001;

    cout << f(n) << endl;

    return 0;
}
