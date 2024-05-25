#include <iostream>
#include <chrono>

using namespace std;

bool palindrome(const string& s) {
    for(int i = 0; i < s.length() / 2; i++)
        if( s[i] != s[s.length() - 1 - i] )
            return false;

    return true;
}

string to_bin(int n) {
    string s = "";
    for( ; n > 0 ; ) {
        if( n & 1 ) 
            s = '1' + s;
        else 
            s = '0' + s;

        n >>= 1;
    }

    return s;
}

int f(int n) {
    int sum = 0;
    
    for(int i = 0; i < n; i++)        
        if( palindrome( to_string(i) ) && palindrome( to_bin(i) ) ) 
            sum += i;
    
    return sum;
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