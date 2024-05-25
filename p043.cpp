#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int factorial(int n) {
    int p = 1;
    
    for(int i = 2; i <= n; i++)
        p *= i;

    return p;
}

bool g(const string& s) {
    int n0 = (s[1] - 48) * 100 + (s[2] - 48) * 10 + (s[3] - 48);
    int n1 = (s[2] - 48) * 100 + (s[3] - 48) * 10 + (s[4] - 48);
    int n2 = (s[3] - 48) * 100 + (s[4] - 48) * 10 + (s[5] - 48);
    int n3 = (s[4] - 48) * 100 + (s[5] - 48) * 10 + (s[6] - 48);
    int n4 = (s[5] - 48) * 100 + (s[6] - 48) * 10 + (s[7] - 48);
    int n5 = (s[6] - 48) * 100 + (s[7] - 48) * 10 + (s[8] - 48);
    int n6 = (s[7] - 48) * 100 + (s[8] - 48) * 10 + (s[9] - 48);

    return  !( n0 %  2 ) &&
            !( n1 %  3 ) &&
            !( n2 %  5 ) &&
            !( n3 %  7 ) &&
            !( n4 % 11 ) &&
            !( n5 % 13 ) &&
            !( n6 % 17 );  
}

uint64_t f() {
    uint64_t sum = 0;
    
    string s = "9876543210";

    int u = factorial(10);
    for(int i = 0; i < u; i++, next_permutation(s.begin(), s.end()))
        if( g(s) )
            sum += stoull(s);
            
    return sum;
}

int main() {
    auto start = chrono::steady_clock::now();
    uint64_t result = f();
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}
