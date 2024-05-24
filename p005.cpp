#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int f(int n) {
    for(int i = n; ; i += n) {
        for(int j = 3; j < n; j++) {
            if( i % j != 0 ) 
                goto continue2;
        }
        return i;
        continue2:;
    }

    return -1;
}

int main() {
    int n = 20;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}

