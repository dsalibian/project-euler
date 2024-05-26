#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;

bool prime(int n) {
    if( !( n & 1 ) )
        return false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

vector<int> soe(int n) {
    vector<bool> v ( n, true);
    v[0] = v[1] = false;

    int u = sqrt(n);
    for(int i = 2; i <= u; i++) 
        for(int j = i * i; j <= n; j += i) 
            v[j] = false;

    vector<int> primes;
    for(int i = 0; i < n - 2; i++) 
        if( v[i] ) 
            primes.push_back(i);

    return primes;
}

int f(int n) {
    vector<int> u = soe(n);
    int u_size = u.size();

    int s_max = 0;
    int s_1 = u[0];
    for(int i = 1; i < u_size; i++)  {
        s_1 += u[i];

        int s = s_1;
        if( s > n )
            return s_max;
        
        for(int j = 0; j < u_size - i; j++) {
            s -= u[j];
            s += u[j + i];

            if( s > n )
                break;

            if( prime(s) ) 
                s_max = s;
        }
    }

    return -1;
}

int main() {
    int n = 1'000'000;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}