#include <iostream>
#include <chrono>

using namespace std;

int f(int n) {
    int sum = 0;
    int a = 1;
    int b = 2; 

    for( ; b <= n; ) {
        if( b % 2 == 0 ) 
            sum += b;

        int t = b;
        b = a + b;
        a = t;
    }
    return sum;
}

int main() {
    int n = 4'000'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
