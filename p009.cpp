#include <iostream>
#include <chrono>

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

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}