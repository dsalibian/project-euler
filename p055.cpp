#include <iostream>
#include <algorithm>

using namespace std;

void trim(string& s) {
    for( ; s.length() > 1 && s[0] == '0'; )
        s.erase(0, 1);
}

string add(const string& a, const string& b) {
    int l = max(a.length(), b.length());

    string fsum (l, '0');

    int carry = 0;
    for(int i = 0; i < l; i++) {
        int ind0 = a.length() - 1 - i;
        int ind1 = b.length() - 1 - i;

        int sum = 0;

        if( ind0 > -1 )
            sum += (int)(a[ind0] - 48);

        if( ind1 > -1 )
            sum += (int)(b[ind1] - 48);

        sum += carry;

        fsum[l - 1 - i] = (char)( ( sum % 10 ) + 48 );
        carry = sum / 10;

    }

    if( carry != 0 )
        fsum = to_string(carry) + fsum;

    trim(fsum);
    return fsum;
}

bool palindrome(const string& s){
    for(int i = 0; i <= s.length() / 2; i++)
        if( s[i] != s[s.length() - i - 1] )
            return false;
    return true;
}

string reverse(const string& s){
    string t = s;
    reverse(t.begin(), t.end());
    return t;
}

bool lychrel(string n) {
    for(int i = 0; i < 300; i++) {
        n = add(n, reverse(n));
        if( palindrome(n) )
            return true;
    }
    return false;
}

int f(int n) {
    int c = n;
    for(int i = 0; i < n; i++)
        if( lychrel( to_string(i) ) )
            c--;
    
    return c;
}

int main() {
    int n = 10'000;
    
    cout << f(n) << endl;

    return 0;
}
