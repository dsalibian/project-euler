#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <algorithm>

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

bool prime(int n) {
    if( n < 2 )
        return false;
    if( n == 2 )
        return true;
    if( !( n & 1) )
        return false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2) 
        if( n % i == 0 ) 
            return false;
    
    return true;
}

bool d(int n, vector<int>& v) {
    int u = sqrt(n);
    for(int i = 1; i <= u; i++) {
        if( !(n % i) ) {
            if( n / i == i ) {
                if( !binary_search(v.begin(), v.end(), i + n/i) )
                    return false;
            }
            else {
                if( !binary_search(v.begin(), v.end(), i + n/i) || !binary_search(v.begin(), v.end(), n/i + n/(n/i)) )
                    return false;
            }
        }
    }

    return true;
}

uint64 f(uint64 n) {
    n = pow(10, n);

    vector<int> arr { soe(n) };

    uint64 sum = 0;
    for(int i = 0; i < arr.size(); i++)
        if( d( arr[i] - 1, arr) )
            sum += arr[i] - 1;

    return sum;
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