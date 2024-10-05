#include <iostream>

using namespace std;

int f(int n) {
    for(int a = 1; a < n; a++) {
        for(int b = a + 1; a + b < n; b++) {
            int c = n - b - a;
            if( a * a + b * b == c * c ) 
                return a * b * c;
        }
    }
    
    return -1;
}

int main() {
    int n = 1'000;

    cout << f(n) << endl;

    return 0;
}
