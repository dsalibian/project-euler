#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
typedef unsigned long long uint64;

vector<int> soe(int n) {
    vector<bool> v ( n, true);
    v[0] = v[1] = false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i+=2) 
        if( v[i] )
            for(int j = i * i; j <= n; j += i) 
               v[j] = false;

    vector<int> primes {2};
    for(int i = 1; i < n; i+=2) 
        if( v[i] ) 
            primes.push_back(i);

    return primes;
}

int s(int p, int q) {
    if( q == 1 )
        return p;

    int c = 0;
    for(int i = p; ; i += p) {
        int t = i;
        for( ; !(t % p); ) {
            if( ++c >= q )
                return i;

            t /= p;
        }

    }
}

uint64 f(uint64 n) {
    n = pow(10, n);

    vector<int> primes { soe(n) };

    vector<int> u (n + 1, 0);
    for(int i = 0; i < primes.size(); i++) {
        for(int j = primes[i]; j <= n; j += primes[i]) { 
            int t = j;
            int c = 0;
            for( ; !(t % primes[i]); c++)
                t /= primes[i];

            u[j] = max(u[j], s(primes[i], c));

        }
    }

    uint64 s = 0;
    for(int i = 0; i < u.size(); i++)
        s += u[i];

    return s;
}

int main() {
    int n = 8;

    auto start = chrono::steady_clock::now();
    uint64 result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}