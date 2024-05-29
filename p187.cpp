#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;

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

int f(uint64_t n) {
    n = pow(10, n);

    vector<int> u { soe(n/2) };

    int c = 0;
    for(int i = 0; i < u.size(); i++) 
        for(int j = i; j < u.size(); j++) 
            if( (uint64_t)u[i]*u[j] < n )
                c++;
            else 
                break;
        
    return c;
}

int main() {
    int n = 8;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}