#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool prime(int n) {
    if( n % 2 == 0 )
        return false;

    int u = sqrt(n);
    for(int i = 3; i <= u; i += 2)
        if( n % i == 0 ) 
            return false;
    
    return true;
}

int f() {
    string o = "987654321";    
    string s = o;
    int n = stoi(s);
    for( ; !prime(n); ) {
        if( s == o ) 
            o = s = s.substr(1, s.length());

        prev_permutation(s.begin(), s.end());    
        n = stoi(s);
    }

    return n;
}

int main() {
    cout << f() << endl;

    return 0;
}
