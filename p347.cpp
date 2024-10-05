#include <iostream>
#include <cmath>
#include <vector>

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

int M(uint64 p, uint64 q, uint64 N) {
    if( p * q > N )
        return 0;

    uint64 max = 0;

    for(int i = 1; (uint64)pow(p, i) * q <= N; i++) {
        uint64 k = pow(p, i);
        for(int j = 1; (uint64)pow(q, j) * k <= N; j++) {
            uint64 t = pow(q, j) * k;
            if( t == N )
                return N;
            else if( t > N )
                break;
            else
                max = std::max(max, t);
        }
    }

    return max;
}

uint64 f(int n) {
    n = pow(10, n);
    
    vector<int> arr { soe(n/2) };

    uint64 sum = 0;
    int u = sqrt(n);
    for(int i = 0; i < arr.size(); i++) {
        uint64 a = arr[i];
        if( a > u )
            break;

        for(int j = i + 1; j < arr.size(); j++) {
            uint64 b = arr[j];
            if( a * b > n )
                break;
            
            sum += M(a, b, n);

        }
    }

    return sum;
}

int main() {
    int n = 7;

    cout << f(n) << endl;

    return 0;
}
