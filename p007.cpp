#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

bool prime(int n) {
    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2) 
        if( n % i == 0 ) 
            return false;
    
    return true;
}

int f(int n) {
    int count = 1;
    for(int i = 3; ; i += 2) {
        if( prime(i) ) 
            count++;
            
        if( count == n ) 
            return i;

    }
}

int main() {
    int n = 10'001;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
}


