#include <iostream>
#include <chrono>

using namespace std;

int next(int n) {
    int s = 0;
    for( ; n > 0; ) {
        int m = n % 10;
        s += m * m;
        n /= 10;
    }
    return s;
}

bool to_89(int n) {
    for( ; n != 1 && n != 89;)
        n = next(n);

    return n == 89;
}

int f(int n) {
    int c = 0;
    for(int i = 1; i < n; i++) 
        if( to_89(i) )
            c++;
    
    return c;
}

int main() {
    int n = 10'000'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}