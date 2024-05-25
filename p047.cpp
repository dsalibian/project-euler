#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

using namespace std;

int d_factors(int n) {
    int count = n & 1 ? 0 : 1;

    for( ; !(n % 2); )
        n /= 2;

    for(int i = 3; i <= sqrt(n); i += 2) {
        if( !(n % i) )
            count++;
        for( ; !(n % i); )
            n /= i;
    }

    if( n != 1 )
        count++;

    return count;
}

bool equal(vector<int>& u, int n) {
    for(int i = 0; i < u.size(); i++)
        if( u[i] != n )
            return false;

    return true;
}

void shift_down(vector<int>& u, int n) {
    for(int i = 1; i < u.size(); i++)
        u[i - 1] = u[i];
    u[ u.size() - 1 ] = n;
}

int f(int n) {
    int sum = 0;
    
    vector<int> arr (n);
    for(int i = 2; i < n + 2; i++)
        arr[i - 2] = d_factors(i);

    int i = n + 3;
    for( ; !equal(arr, n); i++) 
        shift_down(arr, d_factors(i));

    return i - n;  
}

int main() {
    int n = 4;

    auto start = chrono::steady_clock::now();
    int result = f(n);
    auto end = chrono::steady_clock::now();
    
    cout << result << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;

    return 0;
}