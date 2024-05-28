#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

uint64_t f() {
    int c = 0;

    for(int i = 0; i < 10; i++) 
        for(int j = 0; (int)( j * log10(i) ) + 1 >= j; j++) 
            if( (int)( j * log10(i) ) + 1 == j ) 
                c++;
            
    return c;
}

int main() {    
    auto start = chrono::steady_clock::now();
    uint64_t result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}